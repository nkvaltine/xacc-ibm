#***********************************************************************************
# Copyright (c) 2016, UT-Battelle
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#   * Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#   * Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#   * Neither the name of the xacc nor the
#     names of its contributors may be used to endorse or promote products
#     derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# Contributors:
#   Initial API and implementation - Alex McCaskey
#
#**********************************************************************************/
add_executable(teleport_scaffold_ibm teleport_scaffold_ibm.cpp)
target_link_libraries(teleport_scaffold_ibm ${Boost_LIBRARIES} ${XACC_LIBRARIES})
   
add_executable(qft_scaffold_ibm qft_scaffold_ibm.cpp)
target_link_libraries(qft_scaffold_ibm ${Boost_LIBRARIES} ${XACC_LIBRARIES})
   
add_executable(h2_exp_vals_scaffold_ibm h2_exp_vals_scaffold_ibm.cpp)
target_link_libraries(h2_exp_vals_scaffold_ibm ${Boost_LIBRARIES} ${XACC_LIBRARIES})

add_executable(h2_exp_vals_scaffold_ibm_multi_exec h2_exp_vals_scaffold_ibm_multi_exec.cpp)
target_link_libraries(h2_exp_vals_scaffold_ibm_multi_exec ${Boost_LIBRARIES} ${XACC_LIBRARIES})
   
#install(TARGETS teleport_scaffold_ibm DESTINATION examples)
  
#install(TARGETS h2_exp_vals_scaffold_ibm DESTINATION examples)
