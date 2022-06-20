## 运行方式
1. 保证有外网访问权限，执行cmake会自动从GoogleTest，spdlog的git仓库拉取代码，并解决相关依赖问题
2. 手动修改CMAKEList.txt中Qt链接位置
3. 复制适合自己系统、编译器的dll文件(snap7)到build目录


## 对性能的改进措施
1. 第三方库使用静态库导入，提升编译速度
2. 避免对象拷贝，使用移动语义
3. 使用Eigen3作为数值计算库

## 对可扩展的措施
1. 使用MVC架构，避免对Qt框架的依赖，数据存储在Model中，Controller只负责转发请求，保证Model之间的独立性
2. Viewer负责展示数据，
3. 使用cmake代替qmake

## 对于安全性的措施
1. 基于GoogleTest的单元测试与集成测试
2. 程序运行过程中自动生成运行日志
3. 完善了对象生命周期管理，防止内存泄漏

## 对于维护性的措施
1. 同步编写文档
2. 核心模块代码完整注释，doxygen注释风格，配备相应UML类图、结构图
3. 尽量只使用标准库，减少外部依赖

容器尽量使用值语义,否则需要手动内存管理