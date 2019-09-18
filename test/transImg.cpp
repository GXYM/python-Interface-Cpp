#include <iostream>
#include <Python.h>
#include <opencv2/opencv.hpp>
#include <numpy/arrayobject.h>

using namespace std;

int transport()
{
	// Py_SetPythonHome(L"F:/Anaconda/envs/python36");
	Py_Initialize();
	import_array();

	PyRun_SimpleString("import sys"); // 执行 python 中的短语句  
	PyRun_SimpleString("sys.path.append('./')");

	PyObject *pModule(0);
	pModule = PyImport_ImportModule("TestModule");//myModel:Python文件名  
	PyObject *pDict = PyModule_GetDict(pModule);

	cv::Mat img = cv::imread("test.jpg", CV_LOAD_IMAGE_COLOR);
	npy_intp Dims[3] = { img.rows, img.cols, img.channels()}; 
    PyObject *PyArray = PyArray_SimpleNewFromData(3, Dims, NPY_UBYTE, img.data);

	// PyObject *ArgArray = PyTuple_New(1);
	// PyTuple_SetItem(ArgArray, 0, PyArray);
	//从字典属性中获取函数(参数为整数，　函数名为：load_image)
	//PyObject*pFuncFive = PyDict_GetItemString(pDict, "load_image");
	//PyObject_CallObject(pFuncFive, ArgArray);
	
	//参数设置
	PyObject *pArgs = PyTuple_New(3);
	PyTuple_SetItem(pArgs, 0, Py_BuildValue("i",, 1));//0—序号 i表示创建int型变量
	PyTuple_SetItem(pArgs, 1, Py_BuildValue("i",, 2));
	PyTuple_SetItem(pArgs, 2, Py_BuildValue("i", 3));

	//通过字典属性获取模块中的类
    PyRun_SimpleString("print('----------PyDict_GetItemString Example class')");
    PyObject* pClass = PyDict_GetItemString(pDict, "Example");

	//实例化获取的类
    PyRun_SimpleString("print('----------PyInstanceMethod_New test cslass')");
    PyObject *pInstance = PyInstanceMethod_New(pClass);
	PyObject *cInstance = PyObject_CallObject(pClass, NULL);

	PyRun_SimpleString("print('----------PyObject_CallMethod deal_image')");
	PyObject *ArgArray = PyTuple_New(2);
	PyTuple_SetItem(ArgArray, 0, cInstance);
	PyTuple_SetItem(ArgArray, 1, PyArray);

    PyObject *result = PyObject_CallMethod(pInstance, "deal_image", "O", ArgArray);

	//输出返回值
    char* name=NULL;
    PyRun_SimpleString("print('----------PyArg_Parse')");
    PyArg_Parse(result, "s", &name);
    printf("%s\n", name);

	return 2;
}


int main()
{
	transport();
	// system("pause");
	return 0;
}
