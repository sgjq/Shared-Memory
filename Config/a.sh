protoc mem_config.proto --cpp_out=./
protoc --python_out=. mem_config.proto

cp -f mem_config_pb2.py ../python
