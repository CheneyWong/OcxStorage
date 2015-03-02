# OcxStorage

##说明
该程序为满足一个特殊需求而制作.主要功能是在客户端存储键值型数据到 ocx , cookis 或者 storage 完全能替换它的功能,但是这里就用了 ocx ,算是 ocx 的一个 demo 吧.

##使用

- 工程是 VC6 的, 编译后 ocx 会输出到 debug 目录.
- ocx 需要注册, 注册文件已放入 debug 目录, 双击 register.bat 可完成注册.
- demo.html 是示例文件,可以用来测试
- 共有 5个 方法:
	- Clear 清空所有内容
	- Get 读取指定的值
	- Set 设置指定的值
	- Insert 拼接到已存在的值
	- Plus 将指定的值作为整数对待,对其进行加一操作,并返回操作后的值.

##demo
js 调用 ocx 的方法,也放入 debug 目录, 需要 IE 浏览器运行, 且需要在安全选项中开启所有控件支持.
demo 中 `classid="clsid:036E915A-3F08-443A-8D34-5166A50EE4F2"` 在 VC6 工程目录下 *.odl 文件的最后一个.

##详述
[LINK](http://gpio.me/ocx-storage.html)


