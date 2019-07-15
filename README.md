# QiniuToken

一个用于生成 **七牛云-对象存储** 相关凭证的轻量级工具

## 下载与安装

在 [Release](https://github.com/Militch/qiniutoken/releases) 页面中下载合适的压缩包

## 使用

下载并解压完成后，进软件目录，执行 `qiniutoken` 命令

```bash
./qiniutoken \
--ak <your access key> \
--sk <your secret key> \
--scope <your scope> \
--upload
```

### 参数示意

* `ak` :  七牛云所提供的`Access key`
* `sk` :  七牛云所提供的 `Secret key`
* `scope`: 此参数请参考 [七牛云-上传策略](https://developer.qiniu.com/kodo/manual/1206/put-policy) 文档
* `upload`: 使用该参数，将会生成并输出七牛云的**上传凭证**
