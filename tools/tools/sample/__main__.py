import argparse
import os
from subprocess import check_output
import sys
from argparse import ArgumentParser
# from .execute import ExecuteManager
# from .testcases import TestCaseManager
from .utilities import PyColors


def parser():
  usage = 'Usage: python {} FILE/NONE [--wait] [--help]'.format(__file__)
  argparser = ArgumentParser(usage=usage)
  argparser.add_argument('-f', '--fname', help='Specify source code or nothing')
  argparser.add_argument('-c', '--check', action='store_true', help='Check source code before submitting')
  argparser.add_argument('-s', '--set', help='Set contest name')
  args = argparser.parse_args()
  return args.fname, args.set, args.check

def get_contest_name(contest_info_file):
  if os.path.exists(contest_info_file):
    with open(contest_info_file, 'r') as f:
      return f.read()
  else:
    print('Error: set the contest name with -s option.')
    return ''

def get_execute_file_name(file_name):
  if not file_name:
    return ''
  if len(file_name) == 1:
    file_name = file_name + '.cpp'
  if len(file_name) == 5:
    return file_name


CONTEST_INFO = '/tmp/contest_name.txt'
fname, set_name, check_flag = parser()

if set_name:
  with open(CONTEST_INFO, 'w') as f:
    f.write(set_name)
  print('Contest name has been set')
  sys.exit(0)

contest_name = get_contest_name(CONTEST_INFO).strip()
execute_file_name = get_execute_file_name(fname)
if len(contest_name) > 0:
  # tcm = TestCaseManager(contest_name)
  # em = ExecuteManager(contest_name)
  # tcm.fetch_sample_cases(contest_name)
  
  # 引数によって実行関数を制御したい
  if check_flag:
    print('CONTEST: {}  src: {} {}'.format(contest_name, execute_file_name, PyColors.RED_FLASH + ' (only check, never submit)' + PyColors.END))
    # em.execute_with_sample_cases(execute_file_name)
  else:
    print('CONTEST: {}  src: {} {}'.format(contest_name, execute_file_name, PyColors.YELLOW + '(check & submit)' + PyColors.END))
    # em.auto_submit_code(execute_file_name)


  
    


