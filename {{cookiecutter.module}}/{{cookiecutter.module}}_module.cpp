/*
This module needs to be manually added to you setup.py. Consider
adding the following lines:

    from setuptools import Extension

    module = Extension('{{cookiecutter.project}}.{{cookiecutter.module}}',
                sources = ['src/{{cookiecutter.module}}_module.cpp'],
                )

    setup(...
        ext_modules = [ module ],
        )
*/

#include <Python.h>

PyDoc_STRVAR({{cookiecutter.module}}__doc__,
    ":mod:`{{cookiecutter.module}}` - {{cookiecutter.module_short_description}}\n"
    "###########################################\n"
    "\n"
    ".. module:: {{cookiecutter.module}}\n"
    "   :synopsis: {{cookiecutter.module_short_description}}\n"
    ".. moduleauthor:: {{cookiecutter.author}} <{{cookiecutter.email}}>\n"
    "\n"
    "..\n"
    "   {{cookiecutter.copyright}}\n"
    );

const char* __version__ = "{{cookiecutter.release}}";

{% if cookiecutter.new_type %}
/* Type declaration and definition  ----------------------------------------- */


typedef struct {
    PyObject_HEAD
    int initialized;
} {{cookiecutter.new_type}}Object;


static void 
{{cookiecutter.new_type}}_dealloc({{cookiecutter.new_type}}Object* self) {

    if (self->initialized) {
        self->initialized = false;
        self->ob_type->tp_free((PyObject*)self);
        }
    }


static {{cookiecutter.new_type}}Object*
{{cookiecutter.new_type}}_new(PyTypeObject* type, PyObject* args, PyObject* kwds) {

    {{cookiecutter.new_type}}Object* self = ({{cookiecutter.new_type}}Object*)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->initialized = true;
        }

    return self;
    }


static int
{{cookiecutter.new_type}}__init__({{cookiecutter.new_type}}Object* self, PyObject* args, PyObject* kwds) {
    return 0;
    }


static PyMethodDef {{cookiecutter.new_type}}Object_methods[] = {
    {NULL}
    }


static PyTypeObject {{cookiecutter.new_type}}ObjectType = {
    PyObject_HEAD_INIT(NULL)
    0,                          /*ob_size*/
    "{{cookiecutter.module}}.{{cookiecutter.new_type}}", /*tp_name*/
    sizeof({{cookiecutter.new_type}}Object),       /*tp_basicsize*/
    0,                          /*tp_itemsize*/
    (destructor){{cookiecutter.new_type}}_dealloc, /*tp_dealloc*/
    0,                          /*tp_print*/
    0,                          /*tp_getattr*/
    0,                          /*tp_setattr*/
    0,                          /*tp_compare*/
    0,                          /*tp_repr*/
    0,                          /*tp_as_number*/
    0,                          /*tp_as_sequence*/
    0,                          /*tp_as_mapping*/
    0,                          /*tp_hash */
    0,                          /*tp_call*/
    0,                          /*tp_str*/
    0,                          /*tp_getattro*/
    0,                          /*tp_setattro*/
    0,                          /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
    "{{cookiecutter.module}} {{cookiecutter.new_type}} objects",/* tp_doc */
    0,		                    /* tp_traverse */
    0,		                    /* tp_clear */
    0,		                    /* tp_richcompare */
    0,		                    /* tp_weaklistoffset */
    0,		                    /* tp_iter */
    0,		                    /* tp_iternext */
    {{cookiecutter.new_type}}Object_methods,       /* tp_methods */
    0,                          /* tp_members */
    0,                          /* tp_getset */
    0,                          /* tp_base */
    0,                          /* tp_dict */
    0,                          /* tp_descr_get */
    0,                          /* tp_descr_set */
    0,                          /* tp_dictoffset */
    (initproc){{cookiecutter.new_type}}__init__,   /* tp_init */
    0,                          /* tp_alloc */
    (newfunc){{cookiecutter.new_type}}_new,        /* tp_new */
};

{% endif %}

/* Module functions --------------------------------------------------------- */

PyDoc_STRVAR(helloworld__doc__,
        "Greet the world -- hail fellow well met\n"
        );

static PyObject*
helloworld() {
    return PyString_FromString("hello world");
    }


static PyMethodDef module_methods[] = {

    {"helloworld", (PyCFunction)helloworld, METH_NOARGS, helloworld__doc__},

    {NULL}
    };


#ifndef PyMODINIT_FUNC  /* declarations for DLL import/export */
#define PyMODINIT_FUNC void
#endif
PyMODINIT_FUNC
init{{cookiecutter.module}}(void) {

    PyObject* me;

    if (!(me = Py_InitModule3("{{cookiecutter.module}}", module_methods, {{cookiecutter.module}}__doc__))) {
        return;
        }

    /* Set module level versions */

    if (PyModule_AddStringConstant(me, "__version__", __version__))
        goto ErrorReturn;

    return;
    
ErrorReturn:
    Py_XDECREF(me);

    return;
    }

