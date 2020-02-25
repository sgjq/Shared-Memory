# Shared Memory
### C++和python进程间通过共享内存通信，用protobuf编码解码

## 1.依赖项
1.1. **Protobuf**
1.2. **Opencv** (仅测试和传输数据用）

## 2.运行

./pre.sh
cd build
cmake ..
make
./tran_message
cd ../python
python test_mem.py

