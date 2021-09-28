import os
import glob
import configparser
import string
import requests as rq
from bs4 import BeautifulSoup
import pickle

from requests.models import Response

class AtcoderClient:
  def __init__(self, contest_name):
    self._contest_name = contest_name
    self._config = configparser.ConfigParser()
    self._config.read("/home/seiji/workspace/atcoder/tools/tools/sample/config.ini")
    self._develop_path = "{}/{}/{}".format(
      self._config['LOCAL_ENV']['home_path'],
      contest_name.translate(contest_name.maketrans('', '', string.digits)).upper(),
      contest_name
      )
    self._session = rq.session()


  def submit_code(self):
    submit_url = f"https://atcoder.jp/contests/{self._contest_name}/submit"
    source_code = self._get_source_code()

    if source_code == "":
      print ("No code was found!")
      return

    self._login()
    submit_info = {
      "csrf_token": self._get_csrf_token(submit_url),
      "data.TaskScreenName": self.task_screen_name,
      "data.LanguageId": 4003, # cpp
      "sourceCode": source_code
    }
    # response = self._session.post(submit_url, data=submit_info)
    # print(response)

  def _login(self):
    self._load_cookies()
    if self._check_logging_in():
      print('You are already logging in.')
      return

    LOGIN_PATH = 'https://atcoder.jp/login'
    login_info = {
      "csrf_token": self._get_csrf_token(LOGIN_PATH),
      "username": self._config["USER"]["username"],
      "password": self._config["USER"]["password"]
    }
    response = self._session.post(LOGIN_PATH, data=login_info)
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
    return response.text.find('Sign In') == -1

  def _get_csrf_token(self, url):
    response = self._session.get(url)
    page = BeautifulSoup(response.content, "html.parser")
    csrf_token = page.find(attrs={"name":"csrf_token"}).get("value")
    return csrf_token
    
  def _get_source_code(self, extention=".cpp"):
    path = "{}/*{}".format(self._develop_path, extention)
    files = glob.glob(path)
    latest_file_path = ""
    latest_time = 0
    for file in files:
      if latest_time < os.path.getmtime(file):
        latest_time = os.path.getmtime(file)
        latest_file_path = file
    
    source_code = ""
    if latest_file_path == "":
      print ("No {} files exist!".format(extention))
    else:
      self.task_name = (latest_file_path.split("/"))[-1][0]
      self.task_screen_name = self._contest_name + "_" + self.task_name
      with open(latest_file_path, "r") as f:
        source_code = f.read()
    
    return source_code


if __name__ == "__main__":
  ac = AtcoderClient("abc210")
  ac.submit_code()