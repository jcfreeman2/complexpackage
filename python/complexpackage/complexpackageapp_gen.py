# This module facilitates the generation of complexpackage DAQModules within complexpackage apps


# Set moo schema search path                                                                              
from dunedaq.env import get_moo_model_path
import moo.io
moo.io.default_load_path = get_moo_model_path()

# Load configuration types                                                                                
import moo.otypes
moo.otypes.load_types("complexpackage/somedaqmodule.jsonnet")

import dunedaq.complexpackage.somedaqmodule as somedaqmodule

from daqconf.core.app import App, ModuleGraph
from daqconf.core.daqmodule import DAQModule
#from daqconf.core.conf_utils import Endpoint, Direction

def get_complexpackage_app(nickname, some_configured_value, host="localhost"):
    """
    Here the configuration for an entire daq_application instance using DAQModules from complexpackage is generated.
    """

    modules = []

    # JCF: can I reuse this nickname?
    modules += [DAQModule(name = nickname, 
                          plugin = "SomeDAQModule", 
                          conf = somedaqmodule.Conf(some_configured_value = some_configured_value
                            )
                )]

    mgraph = ModuleGraph(modules)
    complexpackage_app = App(modulegraph = mgraph, host = host, name = nickname)

    return complexpackage_app
