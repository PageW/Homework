# 在window10下配置VSCode的C++环境

## 1.gcc编译器

1.1下载gcc编译器

Dropbox里有一个gcc编译器

1.2配置环境变量

C:\Program Files\TDM-GCC-64\bin加入环境变量

## 2.VSCode C++插件

在拓展中搜索C++，安装第一个插件C/C++

## 3.配置tasks.json文件

```json
{
    "version": "2.0.0",
    "tasks": [
      {
        "label": "build",
        "type": "process",
        "command": "g++",
        "args": [
          "-g",
          "-Wall",
          "-std=c++14",
          "-lm",
          "${file}",
          "-o",
          "${fileDirname}/${fileBasenameNoExtension}.o"
        ],
        "presentation": {
          "echo": false,
          "reveal": "silent",
          "showReuseMessage": false
        },
        "problemMatcher": "$gcc",
        "group": {
          "kind": "build",
          "isDefault": true
        },
        "windows": {
          "args": [
            "-g",
            "-Wall",
            "-std=c++14",
            "-lm",
            "${file}",
            "-o",
            "${fileDirname}/${fileBasenameNoExtension}.exe"
          ]
        }
      },
      {
        "label": "run",
        "type": "shell",
        "dependsOn": "build",
        "command": "${fileDirname}/${fileBasenameNoExtension}.o",
        "presentation": {
          "focus": true
        },
        "group": {
          "kind": "test",
          "isDefault": true
        },
        "windows": {
          "command": "${fileDirname}/${fileBasenameNoExtension}.exe"
        }
      }
    ]
  }
```

## 4.配置一键运行

点击左下角齿轮图标，选择键盘快捷方式(keyboard shortcuts)，搜索tasks，找到Tasks: Run Test Tasks，绑定为喜欢的键(我F10)。

## 5.配置调试

在.vscode文件夹中新建launch.json文件，添加如下内容：

```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}.o",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "build",
            "windows": {
                "program": "${fileDirname}/${fileBasenameNoExtension}.exe",
                "miDebuggerPath": "C:/Program Files/TDM-GCC-64/bin/gdb.exe",
            },
            "osx": {
                "externalConsole": true
            },
        }
    ]
}
```

