base_path="/home/seiji/workspace/atcoder/problems/ABC/"

if [ "$#" -ne "1" ]; then
  echo "You need an argument like 'abc123'."
  exit
fi

path="${base_path}${1}"
if [ -e "$path" ]; then
  echo "$path already exists. nothing to do."
  exit
fi

mkdir $path

file="/home/seiji/workspace/atcoder/tools/template/template.cpp"

cp $file "$path/a.cpp"
cp $file "$path/b.cpp"
cp $file "$path/c.cpp"
cp $file "$path/d.cpp"
cp $file "$path/e.cpp"
cp $file "$path/f.cpp"

echo "Successfully created."
