# CAIL2018

该项目为 **CAIL2018** 的代码和模型提交说明。

## 数据集论文
数据集论文 [CAIL2018: A Large-Scale Legal Dataset for Judgment Prediction](https://arxiv.org/pdf/1807.02478.pdf) 已公布。


## 选手交流群

QQ群：237633234

## 提交的文件格式及组织形式

你可以在 ``python_sample`` 中找到最简单的提交代码的格式。你需要将你所有的代码压缩为一个 ``zip`` 文件进行提交，该 ``zip`` 文件内部形式可以参看 ``python_smaple/predictor.zip``。该 ``zip`` 文件内部顶层应该只包含一个叫做 ``predictor`` 的文件夹，在该文件夹下需要有你的所有代码、模型及其他相关的东西。

在压缩包内的 ``predictor`` 文件夹内，你需要保证 ``__init__.py`` 和 ``predictor.py`` 这两个文件一定存在。这两个文件的内容我们将在下文提及。

我们在 ``python_sample`` 的文件夹中提供了 ``main.py``，该代码的逻辑与我们实际运行时的代码逻辑相同，你只需要在 ``python_example`` 的文件夹下运行 ``main.py`` 即可测试你的代码。如有需要，请自行修改该代码。

## 代码的内容

你需要保证 ``__init__.py`` 在文件夹 ``predictor`` 内存在并且内容为：

```from .predictor import Predictor```

你需要保证 ``predictor.py`` 在文件夹 ``predictor`` 内存在，并且其中实现了 ``Predictor`` 这个类。``Predictor`` 类需要实现如下几个函数：

* ``__init__``：你需要在该函数类中完成你模型的各种初始化，并且为该类声明变量 ``batch_size``，该变量代表评测器每次需要给你多少个数据同时进行预测。``batch_size`` 需要是一个大于等于 $1$ 的整数，如果该参数对你来说没有意义，请直接使用 ``self.batch_size=1`` 将该变量设为 $1$。
* ``predict(content)``：在该函数内你需要实现自动判决的预测。参数 ``content`` 为一个长度**不超过** ``batch_size`` 的数组，其中每个元素为一个字符串，对应下载的数据中的事实即 ``fact`` 字段，你需要对每一个数组中的元素进行预测，并返回预测的结果 ``result``。``result``的类型应该为数组，且其元素个数应与 ``content`` 的元素个数相同，并且 ``result`` 中预测的结果顺序应与 ``content`` 中的事实顺序相同。对于每个预测结果，其类型应为 ``dict`` 类型，且包含以下字段：
    * ``accusation``：该字段的类型为一个数组，数组中包含若干个整数，代表预测相关罪名的结果。如 $[1,2,3]$ 表示和第 $1,2,3$ 条罪名都相关，罪名的编号与下发的 ``accu.txt`` 中的顺序一致，从 $1$ 开始编号。
    * ``articles``：该字段的类型为一个数组，数组中包含若干个整数，代表预测相关法条的结果。如 $[1,2,3]$ 表示和第 $1,2,3$ 条法条都相关，法条的编号与下发的 ``law.txt`` 中的顺序一致，从 $1$ 开始编号。**注意**这里的数字并不是代表你预测的结果为法条的第几条，你预测的结果为 $1$ 代表的是 ``law.txt`` 中的第一条法条。
    * ``imprisonment``：该字段类型为一个整数，代表预测的刑期，单位为月。如果预测结果为无期徒刑，请将该字段的值设为 $-1$；如果预测结果为死刑，请将该字段的值设为 $-2$。

以上为 ``predictor.py`` 中你需要实现的内容，你可以利用 ``python_example/predictor`` 下的文件进行进一步参考。**请注意**，代码运行的目录并不是在predictor目录下，而是在predictor的上一级目录，所以请在加载模型的时候尽量使用关于``predictor.py``的相对路径。

## 其他语言的支持

如上文所述，我们现阶段只支持 ``python`` 语言的提交，但是这并不代表你不能够使用其他语言进行预测。我们在 ``c++_sample/predictor`` 下提供了一种可能的 ``c++`` 的实现方法。我们现在仍然需要实现上文所述的 ``predictor.py`` 的各种接口，但是我们在预测的时候利用 ``os.system`` 调用系统命令运行你编译好的可执行文件，或者其他运行你代码的命令。如果你担心可执行文件没有权限，可以像给出的例子在初始化的过程中加上权限。

## 评测脚本

我们在 ``judger`` 文件夹中提供了一个 ``Judger`` 的类可以帮助你计算你三个任务的得分，你可以参考该代码实现你自己的Judger。该Judger所使用的读入格式仅用于我们的评测，如果你需要使用该代码，请根据你的需求自行进行修改。

## 现有python3.5系统环境

```
Package             Version               
------------------- ----------------------
absl-py             0.2.0                 
astor               0.6.2                 
bleach              1.5.0                 
boto                2.48.0                
boto3               1.7.19                
botocore            1.10.19               
bz2file             0.98                  
certifi             2018.4.16             
chardet             3.0.4                 
cycler              0.10.0                
Cython              0.28.2                
docutils            0.14                  
fasttext            0.8.3                 
future              0.16.0                
gast                0.2.0                 
gensim              3.4.0                 
grpcio              1.11.0                
h5py                2.7.1                 
html5lib            0.9999999             
idna                2.6                   
jieba               0.39                  
jmespath            0.9.3                 
JPype1              0.6.3                 
Keras               2.1.6                 
kiwisolver          1.0.1                 
lightgbm            2.1.1                 
Mako                1.0.7                 
Markdown            2.6.11                
MarkupSafe          1.0                   
matplotlib          2.2.2                 
numpy               1.14.3                
pandas              0.22.0                
Pillow              5.1.0                 
pip                 10.0.1                
protobuf            3.5.2.post1           
pycurl              7.43.0                
pygobject           3.20.0                
pygpu               0.7.6                 
pyhanlp             0.1.41                
pyltp               0.2.1                 
pyparsing           2.2.0                 
python-apt          1.1.0b1+ubuntu0.16.4.1        
pytz                2018.4                
PyYAML              3.12                  
requests            2.18.4                
s3transfer          0.1.13                
scikit-learn        0.19.1                
scikit-multilearn   0.0.5                 
scipy               1.1.0                 
seq2seq             0.1.5                 
setuptools          39.0.1                
six                 1.11.0                
sklearn             0.0                   
smart-open          1.5.7                 
tensorboard         1.7.0                 
tensorflow-gpu      1.7.0                 
termcolor           1.1.0                 
tflearn             0.3.2                 
Theano              1.0.1                 
thulac              0.1.2                 
torch               0.3.1                 
torchtext           0.2.3                 
torchvision         0.2.0                 
tqdm                4.23.3                
unattended-upgrades 0.1                   
urllib3             1.22                  
Werkzeug            0.14.1                
wheel               0.31.0                
xgboost             0.71
```

等待补全中

如果你有需要的环境，请联系比赛管理员进行安装。
