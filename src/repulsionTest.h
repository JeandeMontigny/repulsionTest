// -----------------------------------------------------------------------------
//
// Copyright (C) The BioDynaMo Project.
// All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
//
// See the LICENSE file distributed with this work for details.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership.
//
// -----------------------------------------------------------------------------
#ifndef REPULSIONTEST_H_
#define REPULSIONTEST_H_

#include "biodynamo.h"

namespace bdm {

auto set_param = [&](Param* param) {
  param->simulation_time_step_ = 0.01; // default
  param->simulation_max_displacement_ = 3.0; // default
  param->run_mechanical_interactions_ = true;
  param->export_visualization_ = true;
  param->visualization_export_interval_ = 100;
  param->visualize_sim_objects_["Cell"] = {"diameter_"};
};

inline int Simulate(int argc, const char** argv) {
  Simulation simulation(argc, argv, set_param);

  // Define initial model - in this example: single cell at origin
  auto* rm = simulation.GetResourceManager();

  auto* cell0 = new Cell({0, 0, 0});
  cell0->SetDiameter(10);
  cell0->SetMass(10);
  rm->push_back(cell0);

  auto* cell1 = new Cell({2.5, 0, 0});
  cell1->SetDiameter(10);
  cell1->SetMass(10);
  rm->push_back(cell1);

  // Run simulation for one timestep
  simulation.GetScheduler()->Simulate(10000);

  std::cout << "Simulation completed successfully!" << std::endl;
  return 0;
}

}  // namespace bdm

#endif  // REPULSIONTEST_H_
