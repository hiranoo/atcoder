from pickle import FALSE
import sys, os, subprocess
import time
import shutil
import glob
import configparser
import string
import hashlib
import plyer
import requests as rq
from bs4 import BeautifulSoup
from session import SessionManager
from utilities import PyColors

class ExecuteManager(SessionManager, PyColors):
  def __init__(self, contest_name):
    super(ExecuteManager, self).__init__(contest_name)
    self._contest_page_url = '{}/contests/{}'.format(self._config['ATCODER']['top_page_url'], contest_name)
    self._contest_name = contest_name
    self._develop_path = '{}/{}/{}'.format(
      self._config['LOCAL_ENV']['home_path'],
      contest_name.translate(contest_name.maketrans('', '', string.digits)).upper(),
      contest_name
      )
    self._sample_case_path = '{}/{}'.format(self._develop_path, self._config['LOCAL_ENV']['sample_cases_dir'])

  def auto_submit_code(self, file_name=''):
    if self.execute_with_sample_cases() and self.submit_code(file_name):
      print('Submitted code ({})'.format((self.latest_file_path.split('/'))[-1]))

  def _submit_code(self, file_name=''):
    submit_url = f'{self._contest_page_url}/submit'
    source_code = file_name
    if source_code == '':
      source_code = self._get_latest_source_code()
    
    if source_code == '':
      print ('No code was found!')
      return

    is_valid = False
    for file in glob.glob(self._develop_path + '/*'):
      if file == self.latest_file_path:
        is_valid = True
        break
    if not is_valid: return False
    
    SessionManager.login(self)
    submit_info = {
      'csrf_token': SessionManager.get_csrf_token(self, submit_url),
      'data.TaskScreenName': self.task_screen_name,
      'data.LanguageId': 4003, # cpp
      'sourceCode': source_code
    }
    response = self._session.post(submit_url, data=submit_info)
    response.raise_for_status()
    
    return True

  
  def fetch_latest_submission_result(self, task_screen_name):
    submission_url = f'{self._contest_page_url}/submissions/me'
    result = 'WJ'
    while result == 'WJ':
      SessionManager.login(self)
      response = self._session.get(submission_url)
      response = self._session.get(submission_url, params={'f.Task': task_screen_name})
      page = BeautifulSoup(response.text, 'html.parser')
      submission = page.find('tbody').find('tr').find_all('td')
      result = submission[6].text
      time.sleep(1)

    print(result)

    plyer.notification.notify(
      title=task_screen_name,
      message=result,
      app_name='atcoder notifier',
      app_icon='./icon.png',
      timeout=5
    )


  def execute_with_sample_cases(self):
    self._get_latest_source_code()
    compile_command = ['g++', '-std=c++17', '-O', self.latest_file_path]
    error_dir_path = f'{self._develop_path}/errors'
    error_file_path = f'{error_dir_path}/{self.task_screen_name}_error'
    if not os.path.exists(error_dir_path): os.mkdir(error_dir_path)

    with open(error_file_path, 'w') as f:
      try:
        subprocess.run(compile_command, stderr=f)
      except:
        print('Failed to complie.')
        return
    
    if os.path.getsize(error_file_path) > 0:
      with open(error_file_path, 'r') as f:
        print(f.read())
      print(PyColors.PURPLE + PyColors.ACCENT + 'Compile Error' + PyColors.END)
      return

    shutil.move(f'{os.getcwd()}/a.out', f'{self._develop_path}/a.out')
    
    result_file_path = '/tmp/result.txt'
    input_file_path_list = sorted(glob.glob(f'{self._sample_case_path}/{self.task_screen_name}_input*'))
    output_file_path_list = sorted(glob.glob(f'{self._sample_case_path}/{self.task_screen_name}_output*'))
    if len(input_file_path_list) * len(output_file_path_list) == 0:
      print('Fetch test cases first!')
      return False

    execute_result_list = []
    for case_id in range(len(input_file_path_list)):
      with open(input_file_path_list[case_id], 'r') as input_file:
        with open(result_file_path, 'w') as result_file:
          with open(f'{error_file_path}_{case_id}', 'w') as error_file:
            try:
              result = subprocess.run(f'{self._develop_path}/a.out', stdin=input_file, stdout=result_file, stderr=error_file, check=True, timeout=3, shell=True)

            except subprocess.CalledProcessError as e:
              if not os.path.exists(error_dir_path): os.mkdir(error_dir_path)
              execute_result_list.append('RE: {}'.format(e.returncode))
              continue

            except subprocess.TimeoutExpired:
              execute_result_list.append('TLE')
              continue
      
      execute_result_list.append('AC' if self._same_files(result_file_path, output_file_path_list[case_id]) else 'WA')
  
    self._display_list(execute_result_list)

    for res in execute_result_list:
      if res != 'AC': return False
    return True

  def _display_list(self, lis):
    for i, v in enumerate(lis):
      if(v == 'AC'): print(f'case {i+1}: ', PyColors.GREEN + PyColors.ACCENT + v + PyColors.END)
      elif(v == 'WA'): print(f'case {i+1}: ', PyColors.RED + PyColors.ACCENT + v + PyColors.END)
      elif(v == 'TLE'): print(f'case {i+1}: ', PyColors.YELLOW + v + PyColors.END)
      else: print(f'case {i+1}: ', PyColors.RED_FLASH + v + PyColors.END)

  def _same_files(self, file1, file2):
    hash1 = ''
    hash2 = ''
    with open(file1, 'rb') as f:
        hash1 = hashlib.sha256(f.read()).hexdigest()
    with open(file2, 'rb') as f:
      hash2 = hashlib.sha256(f.read()).hexdigest()
    return hash1 == hash2

  def _get_latest_source_code(self, extention='.cpp'):
    path = '{}/*{}'.format(self._develop_path, extention)
    files = glob.glob(path)
    latest_file_path = ''
    latest_time = 0
    for file in files:
      if latest_time < os.path.getmtime(file):
        latest_time = os.path.getmtime(file)
        latest_file_path = file
    
    source_code = ''
    if latest_file_path == '':
      print ('No {} files exist!'.format(extention))
    else:
      self.latest_file_path = latest_file_path
      self.task_screen_name = self._contest_name + '_' + (latest_file_path.split('/'))[-1][0]
      with open(latest_file_path, 'r') as f:
        source_code = f.read()
    
    return source_code


em = ExecuteManager('abc161')
em.auto_submit_code()
# # em.execute_with_sample_cases()
# em.fetch_latest_submission_result('abc161_a')
