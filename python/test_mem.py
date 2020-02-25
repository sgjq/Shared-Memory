# -*- coding:utf-8 -*-

import ctypes
import sys
import sensor_image_pb2 as sensor_image
import res_message_pb2 as res_message
import mem_config_pb2 as mem_config
import cv2
import time

ll = ctypes.cdll.LoadLibrary
#lib = ll("./c_TransmitMessage/lib/libc_rwmemory.so")
lib = ll("../lib/librwmemory.so")


def read_share_memory():
	try:
                lib.read_share_mem.argtypes=[ctypes.c_char_p]
                c_result = lib.getdatasize()
                #print c_result,"\n"
                c_str_buf = ctypes.create_string_buffer(c_result+1)
                lib.read_share_mem(c_str_buf)
                read_string = c_str_buf[:c_result]
                if(len(read_string) != 0):
                        #print "read size:",c_result
                        return read_string;                 
		pass
	except Exception,Ex:
		print Exception,":",Ex

def write_shared_memory(write_str):
    #p_str = ctypes.create_string_buffer(write_str, len(write_str)+1)
    p_str = ctypes.create_string_buffer(write_str)
    lib.write_res_tomemory.argtypes=[ctypes.c_char_p, ctypes.c_int]
    #ret_val=lib.write_res_tomemory(p_str, len(write_str))
    ret_val=lib.write_res_tomemory(p_str, len(p_str))
    if ret_val!=0 :
        print "error write!"
  

def init_shared_memory():
        config = mem_config.MemoryConfig()
        memkey = config.MemoryKey
        memsize = config.MemorySize
        memshift = config.ResShift
        semkey = config.SemaporeKey
        lib.init_share_mem.argtypes=[ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int]
        print memkey," ", memsize, " ", memshift, " ", semkey
        ret_val=lib.init_share_mem(memkey, memsize, memshift, semkey)
        if(ret_val == 0):
             print "init shared memory success!!"

def delete_shared_memory():
    ret_val = lib.detach_share_mem()
    if ret_val!=0:
        print "detach shared mem error!\n"
    else:
        print "detach shared mem success!\n"

    ret_val = lib.delete_share_mem()
    if ret_val!=0:
        print "delete shared mem error!\n"
    else:
        print "delete shared mem success!\n"

def test_read():
    	read_string="0"

	print read_string
        init_shared_memory()
        while 1:
            if lib.isNewMessage():
                break;
	read_string = read_share_memory()
	image = sensor_image.Image()
        image.ParseFromString(read_string)
        print "image.frame_id:", image.frame_id
        print "image.format:", image.format
        print "image.measurement_time:", image.measurement_time
        print "image.width:", image.width
        print "image.step:", image.step        

def test_write():
    src_img = cv2.imread("../1.png")
    cv2.imshow("img", src_img)
    res_mess = res_message.DetectRes()
    res_mess.frame_id = "camera frame"
    res_mess.measurement_time = 0.5
    res_mess.left_topx = 20
    res_mess.left_topy = 60
    res_mess.right_bottomx = 210
    res_mess.right_bottomy = 100
    res_mess.score = 0.83
    serializeToString = res_mess.SerializeToString()
    init_shared_memory()
    write_shared_memory(serializeToString)
    while 1:
        keys = cv2.waitKey(1);
        #print keys,"\n"
        if keys == 97:
            break;
    delete_shared_memory()
    print "finish!"

def test_write_and_Read():
    init_shared_memory()
    cur_time = 0
    res_mess = res_message.DetectRes()
    res_mess.frame_id = "camera frame"
    res_mess.measurement_time = 5.2
    res_mess.left_topx = 20
    res_mess.left_topy = 60
    res_mess.right_bottomx = 210
    res_mess.right_bottomy = 100
    res_mess.score = 0.83
    while 1:
        while 1:
            if lib.isNewMessage():
                break;
        read_string = read_share_memory()
        image = sensor_image.Image()
        image.ParseFromString(read_string)
        print "image.measurement_time:", image.measurement_time
        time.sleep(0.01)
        cur_time = image.measurement_time
        res_mess.measurement_time = cur_time
        serializeToString = res_mess.SerializeToString()
        write_shared_memory(serializeToString)


if __name__=='__main__':
    test_write_and_Read()
   











    
