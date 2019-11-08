#!/usr/bin/env {{cookiecutter.python}}
# vim: set fileencoding=utf-8
# pylint:disable=line-too-long
r""":mod:`test_{{cookiecutter.module}}` - unittests for {{cookiecutter.module}}
##########################################

.. module:: test_{{cookiecutter.module}}
   :synopsis: {{cookiecutter.module_short_description}}
.. moduleauthor:: {{cookiecutter.author}} <{{cookiecutter.email}}>

Comprehensive unittests for {{cookiecutter.module}}

..
   {{cookiecutter.copyright}}"""
# pylint:enable=line-too-long
# ----------------------------------------------------------------------------
# Standard library imports
# ----------------------------------------------------------------------------
import logging
import unittest

# ----------------------------------------------------------------------------
# Module level initializations
# ----------------------------------------------------------------------------
__version__    = '{{cookiecutter.release}}'
__author__     = '{{cookiecutter.author}}'
__email__      = '{{cookiecutter.email}}'
__status__     = 'Testing'
__copyright__  = '{{cookiecutter.copyright}}'

LOG = logging.getLogger('test_{{cookiecutter.module}}')

import {{cookiecutter.module}}


class Test{{cookiecutter.module}}(unittest.TestCase):
    r"""{{cookiecutter.module}} unittest test case"""

    # pylint: disable=invalid-name

    def setUp(self):
        r"""initialize test fixture"""

    def tearDown(self):
        r"""tear down test fixture"""

{% if cookiecutter.project %}
    def test_version(self):
        r"""confirm version exists"""
        self.assertTrue(hasattr({{cookiecutter.module}}, '__version__'))
{% endif %}

if __name__ == '__main__':
    import sys
    sys.exit(unittest.main())
