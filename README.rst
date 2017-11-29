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

Drivers
=======

=============== ================================================================
Driver          Summary
=============== ================================================================
dummy-camera_   A dummy camera driver.
dummy-control_  A dummy gamepad/joystick controller driver.
dummy-gps_      A dummy GPS receiver driver.
dummy-mic_      A dummy microphone driver.
dummy-tag_      A dummy indoor positioning system (IPS) tag driver.
=============== ================================================================

.. _dummy-camera:  https://github.com/conreality/conreality-hal/tree/master/dummy-camera
.. _dummy-control: https://github.com/conreality/conreality-hal/tree/master/dummy-control
.. _dummy-gps:     https://github.com/conreality/conreality-hal/tree/master/dummy-gps
.. _dummy-mic:     https://github.com/conreality/conreality-hal/tree/master/dummy-mic
.. _dummy-tag:     https://github.com/conreality/conreality-hal/tree/master/dummy-tag

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

2. `Opus audio codec (libopus) <https://github.com/xiph/opus>`__ (>= 1.2)

   Required by the dummy mic driver. (To omit, say ``--disable-audio``.)

Installation
============

Installation from Source Code
-----------------------------

Configuring, building, and installing the driver binaries (by default, into
``/usr/local/libexec/conreality``) are all performed with the standard
incantations::

::

   $ ./autogen.sh   # only needed for the development version from Git

   $ ./configure

   $ make

   $ sudo make install

See Also
========

* `Conreality Driver Development Kit (DDK) for C++
  <https://github.com/conreality/conreality-ddk>`__
