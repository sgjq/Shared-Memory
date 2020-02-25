protoc sensor_image.proto --cpp_out=./
protoc --python_out=. sensor_image.proto

protoc res_message.proto --cpp_out=./
protoc --python_out=. res_message.proto

cp -f res_message_pb2.py ../python
cp -f sensor_image_pb2.py ../python
