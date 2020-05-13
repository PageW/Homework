# 本地git推送到github仓库
## 关联Git账号和Github账号
1创建SSH Key  
ssh-keygen -t rsa -C 17210720042@fudan.edu.cn  
执行完成后，.ssh目录下的id_rsa.pub就是生成的公钥  
2将上面的SSH Key添加到github上
在GitHub-setting-SSH and GPG Keys  
完成上述两步骤后，执行
ssh -T git@github.com  
如果出现 You’ve XXX successfully authenticated, but GitHub does not provide shell access。
这就表示已成功连上github。
## 在GitHub上创建空仓库
这个就不详细说了，点击下鼠标的事情，这里要注意的是，最好创建“空”仓库，避免不需要的麻烦，就是在github上创建仓库的时候，除了仓库名称和描述自由填写，其余的保持默认
## push本地仓库代码到GitHub仓库
git init  
git add .  
git commit -m "xxx"  
git remote add origin github仓库的SSH链接  
git push origin master  
