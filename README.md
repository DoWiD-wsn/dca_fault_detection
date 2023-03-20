# Sensor node fault detection in wireless sensor networks utilizing node-level diagnostics #

This repository serves as a collection of information for our sensor node fault detection approach for sensor networks that utilizes node-level diagnostics.
It summarizes the used resources and links to the respective data.
The approach combines the node-level self-diagnostics of the used sensor nodes with an immune-inspired fault detection algorithm based on a modified version of the deterministic dendritic cell algorithm (dDCA).


## Contents ##

* Implementation
  * Sensor node platform
  * Cluster head
  * Sink node
* Evaluation
  * Efficiency analysis
  * Simulation
  * Lab experiments
  * Indoor deployment


## Implementation ##

The entire approach has been implemented in a real wireless sensor network (WSN) consisting of several sensor nodes, a cluster head, and a sink node.
Information on the particular parts is presented in the following.


### Sensor node platform ###

The sensor nodes are based on the [AVR-based sensor node with XBee radio](https://github.com/DoWiD-wsn/avr-based_sensor_node), or short `ASN(x)`.
The nodes were programmed in C-language on the bare metal (i.e., without an operating system).
The sensor node source codes used in our experiments are located in the [source/sensor_node/](tree/master/source/sensor_node) directory (see the contained [README](/source/sensor_node/README.md) for further information).


### Cluster head ###

The cluster head is based on a Raspberry Pi 3 Model B+.
Information on the general setup and the program execution is available in the [README](source/cluster_head/README.md) located in the [source/cluster_head/](tree/master/source/cluster_head) directory.
The Python script implementing the data and fault assessment is also located in that directory (see [rpi_cluster_head.py](source/cluster_head/rpi_cluster_head.py))


### Sink node ###

Like the cluster head, also the sink node is based on a Raspberry Pi 3 Model B+.
Information on its components and setup is available in the [README](source/sink_node/README.md) located in the [source/sink_node/](tree/master/source/sink_node) directory.


## Evaluation ##

Our approach was evaluated with a tripartite setup consisting of simulations, a lab experiment setup, and an indoor WSN deployment.
Details on each experiment are given below.


### Efficiency analysis ###

To evaluate the approach's efficiency, we analyzed its resource overhead.
In this context, we compared the memory requirements of the sensor node software with and without our detection approach enabled.
First, the version without the fault detection and without any node-level diagnostics is available in the [analyses/resource_overhead/sensor_node_without_diagnostics](tree/master/analyses/resource_overhead/sensor_node_without_diagnostics) directory containing the [source file](analyses/resource_overhead/sensor_node_without_diagnostics/sn-diag_disabled.c) and the [avrsize output](analyses/resource_overhead/sensor_node_without_diagnostics/memory_usage.txt).
Second, an example implementation of the entire approach is provided in the [analyses/resource_overhead/sensor_node_with_diagnostics/](tree/master/analyses/resource_overhead/sensor_node_with_diagnostics) directory, again containing the [source file](analyses/resource_overhead/sensor_node_with_diagnostics/sn-diag_enabled.c) and the [avrsize output](analyses/resource_overhead/sensor_node_with_diagnostics/memory_usage.txt).
The comparison is based on the memory calculation of the `avr-size` tool.
In both cases, the sources were compiled with optimization for size (`-Os`) and link-time optimization (`-lfto`).


### Simulation ###

We ran several simulations where we randomly injected faults in one of three base datasets.
The base datasets were recorded from our WSN deployments and show fault-free sensor values and node-level diagnostics.
The injected faults, on the other hand, are based on fault signatures captured in our previous works and our lab experiments described below.
The base datasets, the fault signatures, and the Python scripts used for the simulation are available in the [analyses/simulation/](tree/master/analyses/simulation) directory.
The datasets generated during our simulations and the respective results of our fault detection approach as well as visualizations of the used data are stored in the included [results](tree/master/analyses/simulation/results) directory.


### Lab experiments ###

Additionally, we performed several experiments in a lab setup to evaluate the reaction of our approach to various environmental influences partly while forcing the sensor node in faulty conditions.
In this setup, the environmental conditions of the sensor node were controlled by a [Embedded Testbench](https://github.com/DoWiD-wsn/embedded_testbench) (short ETB).
The scripts used to control the ETB during the experiments are given in the [analyses/lab_experiments/source/embedded_testbench/](tree/master/analyses/lab_experiments/source/embedded_testbench) directory.
In contrast to the indoor WSN deployment discussed below, the sensor node transmitted the data directly to the ETB via UART rather than sending it via Zigbee.
The use sensor node source code is located in the [analyses/lab_experiments/source/sensor_node/](tree/master/analyses/lab_experiments/source/sensor_node) directory.


### Indoor deployment ###

Our indoor deployment consists of seven sensor nodes that included our node-level diagnostics.
As stated above, the source code is available in the [source/sensor_node/](tree/master/source/sensor_node) directory.
