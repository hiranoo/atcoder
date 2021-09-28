import os
import glob
import configparser
import string
import time
import requests as rq
from bs4 import BeautifulSoup
from session import SessionManager

class TestCaseManager(SessionManager):
  
  def __init__(self, contest_name):
    super(TestCaseManager, self).__init__(contest_name)
    self._contest_name = contest_name
    self._develop_path = '{}/{}/{}'.format(
      self._config['LOCAL_ENV']['home_path'],
      contest_name.translate(contest_name.maketrans('', '', string.digits)).upper(),
      contest_name
      )
    self._top_url = self._config['ATCODER']['top_page_url']
    self._contest_top_url = self._top_url + f'/contests/{contest_name}'


  def fetch_sample_cases(self):
    task_url_list = self.fetch_task_url_list()
    sample_cases_path = self._develop_path + '/' + self._config['LOCAL_ENV']['sample_cases_dir']
    try:
      os.mkdir(sample_cases_path)
    except OSError:
      # print('Sample case dir already exists.')
      return

    for task_url in task_url_list:
      # SessionManager.login(self)
      response = self._session.get(task_url)
      page = BeautifulSoup(response.text, 'html.parser')
      time.sleep(1)
      samples = page.find_all('pre')
      samples = samples[1:int(len(samples)/2)]
      inputs = [x.text.replace('\r', '') for i, x in enumerate(samples) if i%2 == 0]
      outputs = [x.text.replace('\r', '') for i, x in enumerate(samples) if i%2 == 1]
      task_id = (task_url.split('/'))[-1]
      for i in range(len(inputs)):
        input_file_name = '{}_input_{}.txt'.format(task_id, i+1)
        output_file_name = '{}_output_{}.txt'.format(task_id, i+1)
        with open(sample_cases_path + '/' + input_file_name, 'w') as f:
          f.write(inputs[i])
        with open(sample_cases_path + '/' + output_file_name, 'w') as f:
          f.write(outputs[i])
    
    
  def fetch_task_url_list(self):
    task_page_url = self._contest_top_url + '/tasks'
    SessionManager.login(self)
    response = self._session.get(task_page_url)
    time.sleep(1)
    page = BeautifulSoup(response.text, 'html.parser')
    task_table = page.find('tbody').find_all('td')
    task_url_list = [self._top_url + td.find('a').get('href') for i, td in enumerate(task_table) if i%5 == 0]
    return task_url_list


tcm = TestCaseManager('abc161')
tcm.fetch_sample_cases()