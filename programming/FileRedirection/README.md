# 输入输出重定向
** cmd
```
cl FileRedirection.cpp
FileRedirection.exe < Sdata.txt
```

** powershell
```
cl FileRedirection.cpp
Get-Content Sdata.txt | .\FileRedirection.exe > out.txt
```
或者
```
"输入字符" | .\FileRedirection.exe
```

** linux
```
g++ FileRedirection.cpp
./a.out < Sdata.txt > out.txt
```
