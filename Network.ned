//
// Copyright (C) 2014 OpenSim Ltd.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//


import inet.common.lifecycle.LifecycleController;
import inet.common.scenario.ScenarioManager;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.physicallayer.idealradio.IdealRadioMedium;
import inet.visualizer.integrated.IntegratedVisualizer;


//import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;
//import inet.common.misc.ThruputMeteringChannel;

network Network
{
    parameters:
        int numHosts;

//    types:
//        channel C extends ThruputMeteringChannel
//        {
//            delay = 0.1us;
//            datarate = 100Mbps;
//            thruputDisplayFormat = "#N";
//        }

    submodules:
        visualizer: IntegratedVisualizer {
            @display("p=100,50");
        }
        radioMedium: IdealRadioMedium {
            parameters:
                @display("p=50,50");
        }

        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=50,150");
        }
        lifecycleController: LifecycleController {
            parameters:
                @display("p=50,200");
        }
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xml("<scenario/>"));
                @display("p=50,250");
        }


        configurator: IPv4NetworkConfigurator {
            parameters:
                @display("p=50,100");
        }
    connections allowunconnected:
}

import src.node.AODVQoSRouter;
network AODVQoSNetwork extends Network
{
    submodules:
        host[numHosts]: AODVQoSRouter {
            parameters:
                @display("p=100,100;r=,,#000040");
        }
}

import inet.node.aodv.AODVRouter;
network AODVNetwork extends Network
{
    submodules:
        host[numHosts]: AODVRouter {
            parameters:
                @display("p=100,100;r=,,#000040");
        }
}
import inet.node.inet.WirelessHost;
network StaticNetwork extends Network
{
    submodules:
        host[numHosts]: AODVQoSRouter {
            parameters:
                @display("p=100,100;r=,,#000040");
                
        }
}


