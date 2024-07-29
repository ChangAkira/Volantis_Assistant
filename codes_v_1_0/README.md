# Volantis_Assistant

一个Hexo框架-Voalntis主题的书写博客助手，帮助快速书写一些非标准MarkDown写法。通过修改规则，也可用于Hexo的其它主题。

## 重要提示

由于作者水平太差了，所以除主界面外，请使用页面上的“Back”按钮返回，否则会引发错误。

## About

Volantis是Hexo框架的一个主题，官方网站[*Volantis*](https://volantis.js.org/).
  
Volantis主题提供一些插件等的快捷写法以及很多主题带来的元素效果。仅以插入图片来说，有四五种效果、功能不尽相同的写法。我在写自己的博客时，经常需要一边看Volantis文档一边写。有一次，我在网上学了一种前端效果并用在自己的博客文章中，后来才发现Volantis已经有该效果插件，不需要自己再写。这些增加了作者的书写量，带来了一些重复性的工作，作者需要记忆相当量的MarkDown“方言”。于是我编写了这样一个工具，使常用的一些非标准MarkDown写法插入变得简单。

该工具简化了博客书写过程，让作者更加专注于内容本身的书写。通过配置规则集文件，也可以适用于其它主题。

本项目为开源项目，使用Qt5.7.1.0框架编写。本人学生，才思不足，疏漏百出。如果对你有一点点的帮助，希望点一个标星，或在B站介绍视频中点一个免费的赞。

项目介绍视频在B站，代码开源于Github，部分细节在我的博客网站中介绍。

在这里，我想感谢学校、BOE俱乐部对我的帮助。

## 介绍

### 各界面介绍

#### 主界面
![主界面](https://i0.hdslb.com/bfs/article/b123ea02e2d33e79799e9e3e2df31d47481184837.png)

#### About

![About](https://i0.hdslb.com/bfs/article/60dd249de369597946883b3b0fe30045481184837.png)

跟上文的About内容是一样的。

#### 选择规则集页面

![选择规则集页面](https://i0.hdslb.com/bfs/article/0d706abc9b6a8af6f195e9a9d5882696481184837.png)

在编辑规则集和开始一个新编辑之前均会出现。支持三个规则集文件，规则集文件是保存在软件目录下的形如 *"rule_set_1"* 的.txt文件。首次打开软件时创建这三个默认规则集。

#### 编辑规则集页面

![编辑规则集页面](https://i0.hdslb.com/bfs/article/3c2064d7a894359c218b706b6b56fa7f481184837.png)

读取规则集文件并显示。在输入框中任意编辑，点击该界面上的"SAVE"按钮保存。

#### 摸鱼界面

还没做。

**注意**

不可同时打开多个编辑规则集界面。（软件中已做限制）

#### 编辑文字界面

![编辑文字界面](https://i0.hdslb.com/bfs/article/237597fb3950820244c77b44a6783dee481184837.png)

点击右侧按钮，插入对应语法。请在文字框中使用<kbd>Ctrl</kbd> + <kbd>C</kbd> 和 <kbd>Ctrl</kbd> + <kbd>V</kbd>。

可以同时打开多个编辑文字界面。不能同时打开编辑规则集界面和编辑文字界面。（软件中已做限制）

### 规则集文件具体介绍

#### 规则集文件示例

![规则集文件示例](https://i0.hdslb.com/bfs/article/cca4e64978d2245f7085ff9724e4d497481184837.png)

#### 提示文字

形如 **{:%规则集名%:}** 的内容为直接使用记事本(NotePad)等打开规则集文件时的提示文字，~~没什么用处。~~这段字符之后就是会在编辑时插入的文字。

#### 需自己填写的字段

下划线+文字的内容表示这部分是在编辑文字时需要自己填写的地方。这部分内容有：

1. _链接  _IMG_链接
2. _宽度  _高度
3. _文字
4. _标题
5. _参数参考各类便签    *在便签块儿(NodeBlock)中*
6. _颜色
7. _这里随便写点什么，但同一个页面内多个Tab块儿这里的内容不能重复    *在Tabs中*
8. _时间线标题
9. _网盘类型  _PSW  _FILE_名称    *_PSW表示的是网盘提取码*

编辑时，插入相应MarkDown写法后，应将这部分内容替换为自己需要的内容。

#### 可省略的字段

规则集中，以~$ $~来包裹可省略的字段。

如复选框 `{:%复选框%:}{% checkbox ~$_颜色$~ ~$checked$~ ::_文字 %}`

在编辑文字时插入后，文字编辑框中就会出现`{% checkbox ~$_颜色$~ ~$checked$~ ::_文字 %}`。这是，我们将 *_文字* 替换为我们需要的文字。而被~$ $~包裹的 *_颜色* 和 *checked* 字段为可省略字段。

如果不需要可省略字段，应将其（连同 *~$ $~* 符号）删除。若需要该可省略字段，则只需要删除 *~$ $~* 符号。

如，这些是正确的：

1. `{% checkbox  ::_文字 %}`    复选框样式文字。
2. `{% checkbox  checked ::_文字 %}`    选中的复选框样式文字。
3. `{% checkbox blue ::_文字 %}`    蓝色的复选框样式文字。
4. `{% checkbox blue checked ::_文字 %}`    蓝色的选中的复选框样式文字。

#### 换行

在规则集文件中，使用汉字字符“丨”（gun，三声）作为换行符。在自定义规则中需要换行的，只需要在需要换行的地方插入 **一个** “丨”，程序中就会自动插入空行。

#### 请不要随意在记事本(NotePad)中修改

由于程序中已经写死，所以规则集文件最多有50行，且前45行顺序调换后会导致提示文字和实际输入MarkDown写法不匹配。

#### 对参数有疑问？

对参数有疑问的部分，请查阅[Volantis标签插件文档](https://volantis.js.org/v5/tag-plugins)。

## 使用

首先，使用命令行新建文件。打开文件，自行输入标签(tags)、目录(categories)等（这些和不使用软件是一样的）。

接下来打开软件。确认规则集无误。打开编辑页面。

编辑完成后，将内容复制到文件中。

## 相关页面

1. 我的博客页面[HiVolanyisAssistant](https://changakira.github.io/2024/07/24/HiVolanyisAssistant/)
2. B站[*https://space.bilibili.com/481184837*](https://space.bilibili.com/481184837)
3. 邮箱[*a259759666@163.com*](mailto:a259759666@163.com)
4. gitter聊天室[*https://app.gitter.im/#/room/#maimuju:gitter.im*](https://app.gitter.im/#/room/#maimuju:gitter.im)

如果还有任何问题，我期望得到与你的联系！