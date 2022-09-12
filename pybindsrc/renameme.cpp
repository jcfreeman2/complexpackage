/**
 * @file renameme.cpp
 *
 * This is part of the DUNE DAQ Software Suite, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "pybind11/operators.h"
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sstream>

namespace py = pybind11;

namespace dunedaq::complexpackage::python {

void
register_renameme(py::module& m)
{}

} // namespace dunedaq::complexpackage::python
