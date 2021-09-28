base_path=`pwd`

if [ "$#" -ne "1" ]; then
  echo "Specify the file name as an argument."
  exit
fi

path="${base_path}/${1}"
if [ -e "$path" ]; then
  echo "${1} already exists. nothing to do."
  exit
fi

TEMPLATE_CPP="/home/seiji/workspace/atcoder/tools/template/template.cpp"

cp $TEMPLATE_CPP $path

echo "Successfully created ${1}."
