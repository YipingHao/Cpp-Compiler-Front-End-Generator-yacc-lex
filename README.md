# C++编译器前端生成器（lex yacc）

#### 介绍
C++编译器前端生成器:按照编译器领域经典教科书——龙书上描述的算法编写的编译器前端生成器，包含词法分析器生成器和文法分析器生成器。支持LR(0)和LR(1)两种文法分析方式。
它只有两个文件，automata.cpp,automata.h。词法分析不支持向前看（话说这个功能需要的人很多吗？）词法分析目前也不支持中文，只支持ASCII编码的文件。对于一般用户，这可能是个大问题。目前还没来得及改进。
#### 软件架构



#### 安装教程

1.  使用它的人只需要编译automata.cpp，链接编译后结果就可以使用。另外需要在代码文件中#include"automata.h"。
2.  测试代码写在main.cpp里面。这个文件包含了之前某些项目内的无用代码所以显得十分庞大。如果对测试项目的正确性不感兴趣无需了解main.cpp。
3.  测试用的参数文件是parameter.txt,测试用的数据文件有很多。测试用的文法规则均来自龙书的例子。

#### 使用说明

1.  抱歉截止此次更新，作者只写完了核心部分，没有很好的输入输出外设，所以十分难用。所以使用起来很困难。
2.  外设写完了再在此处更新使用说明的细节
3.  xxxx

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


#### 特技

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)
