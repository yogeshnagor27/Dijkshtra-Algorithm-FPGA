## Dijkshtra Algorithm Implementation on FPGA

## Aim
The goal of this project is to implement the Dijkshtra Algorithm on an FPGA and compare its performance with a CPU. The Dijkshtra Algorithm is used to find the shortest distance between two points in a given graph.

## Overview
FPGAs, or Field Programmable Gate Arrays, are semiconductor devices based on a matrix of configurable logic blocks connected via programmable interconnects. Unlike normal CPUs, FPGA is known for parallel computing. In this project, we are curious to know if the Dijkshtra Algorithm works better on FPGA compared to CPU. We will be comparing the time taken by FPGA and CPU on Jupyter Notebook to draw further conclusions.

## Tasks
The major tasks that need to be completed for implementing the algorithm are as follows:

- Creating IP using Vitis HLS
- Creating Overlay using Vivado
- Designing Jupyter Notebook
- Comparing CPU and FPGA results

## Errors Faced with Solutions
During the implementation of the project, we encountered an issue with the DMA Receive channel. Initially, we used DMA but did not get the output. The following command was running forever in Jupyter while fetching the results: dma.recvchannel.wait(). To resolve this issue, we redesigned the Overlay without DMA, using the registers of the ZYNQ processor as an alternative.

## Technologies Used
- Vitis HLS
- Vivado
- Jupyter Notebook
- FPGA
- CPU

## Conclusion
By comparing the time taken by FPGA and CPU on Jupyter Notebook, we will be able to draw conclusions about which device performs better for the Dijkshtra Algorithm.
