/***********************************************************************************
 * Copyright (c) 2016, UT-Battelle
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the xacc nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Contributors:
 *   Initial API and implementation - Alex McCaskey
 *
 **********************************************************************************/
#include "XACC.hpp"

// Quantum Kernel executing teleportation of
// qubit state to another.
// test


//written with OpenQasm

const std::string src("__qpu__ teleport(AcceleratorBuffer b){\n"
	"   qreg q[3];\n"
	"	creg c0[1];\n"
// Pauli gate: bit-flip
	" 	u3(pi,0,pi) q[0];\n"
// Clifford gate: Hadamard
	"	u2(0,pi) q[1] ;\n"
	"   cx q[1],q[2];\n"
	"   cx q[0],q[1];\n"
	"   cx q[1],q[2];\n"
	"   cx q[2],q[0];\n"
	"   measure q[2] -> c0[0];\n"
	"}\n");

int main (int argc, char** argv) {

	// Initialize the XACC Framework
	xacc::Initialize(argc, argv);

	//set the compiler to use quil
	xacc::setCompiler("quil"); 

	// Create a reference to the 
	// QPU 
	auto qpu = xacc::getAccelerator("rigetti");
	//auto qpu = xacc::getAccelerator("ibm");
	//auto qpu = xacc::getAccelerator("tnqvm");

	// Allocate a register of 3 qubits
	auto qubitReg = qpu->createBuffer("qreg", 3);

	// Create a Program
	xacc::Program program(qpu, src);

	// Request the quantum kernel representing
	// the above source code
	auto teleport = program.getKernel("teleport");

	// Execute!
	teleport(qubitReg);


	//save the IR to text
	//std::ofstream IRout;
	//IRout.open("IRout.txt");
	//program.getIR()->persist(IRout);
	//IRout.close();
	
	//print out the results
	std::vector<std::string> measurements = qubitReg->getMeasurementStrings();
	std::cout << "getMeasurementStrings: ";
	for(auto meas : measurements)  std::cout << meas << " ";
	std::cout << std::endl;
	
	std::cout << "getExpectationValueZ: " << qubitReg->getExpectationValueZ() << std::endl;
	
	//print is not implemented for all accelerators it seems
	//qubitReg->print(std::cout);


	// Finalize the XACC Framework
	xacc::Finalize();

	return 0;
}



