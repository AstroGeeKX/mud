 ### 提交Pull Request（PR）的步骤

提交Pull Request（PR）是在使用Gitee等代码托管平台时，向原始仓库贡献代码的过程。以下是基于搜索结果和最佳实践的步骤:

1. **Fork仓库**：
   - 首先，您需要在Gitee上找到您想要贡献代码的仓库，并点击“Fork”将其复制到您的个人账户中。

2. **克隆Fork的仓库到本地**：
   - 使用`git clone`命令将您Fork的仓库克隆到本地计算机上。
   - 克隆时，您可以选择使用HTTPS或SSH，如果使用SSH，需要确保您的本地机器上有正确配置的SSH密钥。

3. **添加原始仓库作为上游远程**：
   - 在本地仓库中，使用`git remote add upstream <原始仓库的URL>`命令添加原始仓库作为上游远程。

4. **同步上游仓库的最新代码**：
   - 使用`git fetch upstream`和`git merge upstream/main`（或`master`，取决于仓库使用的分支名称）命令更新您的本地仓库，确保您的代码是最新的。

5. **创建新的分支进行开发**：
   - 在本地创建一个新的分支，使用`git checkout -b my-feature-branch`，其中`my-feature-branch`是您的分支名称。
   - 在这个分支上进行您的代码修改。

6. **提交代码到本地分支**：
   - 使用`git add`命令添加修改的文件到暂存区，使用`git commit`命令提交代码到本地分支。

7. **推送本地分支到您的Gitee仓库**：
   - 使用`git push origin my-feature-branch`将本地分支推送到您的Gitee仓库。

8. **创建Pull Request**：
   - 在Gitee上，切换到您的Fork仓库，导航到“Pull requests”选项卡，点击“New pull request”。
   - 选择您的分支作为要合并的来源分支，并选择原始仓库的适当目标分支（通常是`main`或`master`）。
   - 填写Pull Request的标题和描述，说明您的修改内容和目的。

9. **等待审核**：
   - 提交Pull Request后，原始仓库的维护者和其他贡献者将会对您的代码进行审查。
   - 根据反馈进行必要的修改。

10. **合并Pull Request**：
    - 一旦您的代码通过审查，维护者会将其合并到原始仓库中。

请确保遵循目标仓库的贡献指南和代码风格，这有助于加快审查过程并提高合并的可能性。在提交Pull Request之前，最好在本地进行彻底的测试，以确保您的代码质量。