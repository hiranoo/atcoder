import os
import glob
import configparser
import string
import requests as rq
from bs4 import BeautifulSoup
import pickle

class SessionManager:
  def __init__(self, contest_name):
    self._config = configparser.ConfigParser()
    self._config.read('/home/seiji/workspace/atcoder/tools/tools/sample/config.ini')
    self._session = rq.session()

  def get_csrf_token(self, url):
    response = self._session.get(url)
    response.raise_for_status()
    page = BeautifulSoup(response.content, 'html.parser')
    csrf_token = page.find(attrs={'name':'csrf_token'}).get('value')
    return csrf_token

  def login(self):
    self._load_cookies()
    if self._check_logging_in():
      # print('You are already logging in.')
      return

    LOGIN_PATH = 'https://atcoder.jp/login'
    login_info = {
      'csrf_token': self._get_csrf_token(LOGIN_PATH),
      'username': self._config['USER']['username'],
      'password': self._config['USER']['password']
    }
    response = self._session.post(LOGIN_PATH, data=login_info)
    response.raise_for_status()
    self._save_cookies()

  def _save_cookies(self):
    with open(self._config['LOCAL_ENV']['cookie_path'], 'wb') as f:
      pickle.dump(self._session.cookies, f)
  
  def _load_cookies(self):
    cookie_path = self._config['LOCAL_ENV']['cookie_path']
    if os.path.exists(cookie_path):
      with open(cookie_path, 'rb') as f:
        self._session.cookies.update(pickle.load(f))

  def _check_logging_in(self):
    check_url = 'https://atcoder.jp/home'
    response = self._session.get(check_url)
    response.raise_for_status()
    return response.text.find('Sign In') == -1
