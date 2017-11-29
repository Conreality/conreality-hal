*******************************************
Conreality Hardware Abstraction Layer (HAL)
*******************************************

.. image:: https://img.shields.io/badge/license-Public%20Domain-blue.svg
   :alt: Project license
   :target: https://unlicense.org/

.. image:: https://img.shields.io/travis/conreality/conreality-hal/master.svg
   :alt: Travis CI build status
   :target: https://travis-ci.org/conreality/conreality-hal

|

https://wiki.conreality.org/HAL

Prerequisites
=============

Build Prerequisites
-------------------

* Clang_ (>= 3.4) or GCC_ (>= 5.0)
* `GNU Autoconf`_ (>= 2.69)
* `GNU Automake`_ (>= 1.15)
* `GNU Make`_ (>= 3.81)
* pkg-config_ (>= 0.29)

.. _Clang:        https://clang.llvm.org/
.. _GCC:          https://gcc.gnu.org/
.. _GNU Autoconf: https://www.gnu.org/software/autoconf/
.. _GNU Automake: https://www.gnu.org/software/automake/
.. _GNU Make:     https://www.gnu.org/software/make/
.. _pkg-config:   https://www.freedesktop.org/wiki/Software/pkg-config/

Dependencies
============

Build Dependencies
------------------

1. `Conreality Driver Development Kit (DDK) for C++
   <https://github.com/conreality/conreality-ddk>`__

   The ``./configure`` step must be able to find the ``conreality/ddk.h``
   header file. In case your DDK installation *isn't* in a standard system
   header inclusion path such as ``/usr/include`` or ``/usr/local/include``,
   you will need to set the ``CPPFLAGS`` environment variable such that the
   C++ preprocessor can find the DDK header files; for example, to directly
   refer to a local Git clone of the DDK source code repository::

      $ export CPPFLAGS="-I/path/to/conreality-ddk/src $CPPFLAGS"

Installation
============

Installation from Source Code
-----------------------------

::

   $ ./autogen.sh   # only needed for the development version from Git

   $ ./configure

   $ make

   $ sudo make install

See Also
========

* `Conreality Driver Development Kit (DDK) for C++
  <https://github.com/conreality/conreality-ddk>`__
