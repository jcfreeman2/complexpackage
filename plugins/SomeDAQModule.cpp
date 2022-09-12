/**
 * @file SomeDAQModule.cpp
 *
 * Implementations of SomeDAQModule's functions
 *
 * This is part of the DUNE DAQ Software Suite, copyright 2020.
 * Licensing/copyright details are in the COPYING file that you should have
 * received with this code.
 */

#include "SomeDAQModule.hpp"

#include "complexpackage/somedaqmodule/Nljs.hpp"
#include "complexpackage/somedaqmoduleinfo/InfoNljs.hpp"

#include <string>

namespace dunedaq::complexpackage {

SomeDAQModule::SomeDAQModule(const std::string& name)
  : dunedaq::appfwk::DAQModule(name)
{
  register_command("conf", &SomeDAQModule::do_conf);
}

void
SomeDAQModule::init(const data_t& /* structured args */)
{}

void
SomeDAQModule::get_info(opmonlib::InfoCollector& ci, int /* level */)
{
  somedaqmoduleinfo::Info info;
  info.total_amount = m_total_amount;
  info.amount_since_last_get_info_call = m_amount_since_last_get_info_call.exchange(0);

  ci.add(info);
}

void
SomeDAQModule::do_conf(const data_t& conf_as_json)
{
  auto conf_as_cpp = conf_as_json.get<somedaqmodule::Conf>();
  m_some_configured_value = conf_as_cpp.some_configured_value;
}

} // namespace dunedaq::complexpackage

DEFINE_DUNE_DAQ_MODULE(dunedaq::complexpackage::SomeDAQModule)
