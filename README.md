# Ardor
A C++ base game engine.
For learn graphics render.

## 一期目标:
加载一个3D模型,并渲染出来. 

2020/04/29

## 第三方库
glm：数学库

Assimp：模型加载库

glad：OpenGL加载库

glfw：跨平台窗口库

## 代码规范
### 注释 
// 这是注释
### 命名
类成员变量m开头+匈牙利命名法，比如：mName

全局变量g开头+匈牙利命名法，比如：gName

函数对外接口首字母大写，对内接口首字母小写

所有类需要加命名空间

## 编译
git clone https://github.com/CTMStudio/Ardor.git

git submodule update --init

mkdir .build

cd .build

cmake ..