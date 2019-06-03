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

inline int Simulate(int argc, const char** argv) {
  Simulation simulation(argc, argv);
  auto* rm = simulation.GetResourceManager();

  auto* cell0 = new Cell({0, 0, 0});
  cell0->SetDiameter(10);
  cell0->SetMass(1);
  rm->push_back(cell0);

  auto* cell1 = new Cell({5, 0, 0});
  cell1->SetDiameter(10);
  cell1->SetMass(1);
  rm->push_back(cell1);

  // Run simulation for one timestep
  simulation.GetScheduler()->Simulate(25);

  std::cout << "final distance: " << cell1->GetPosition()[0] - cell0->GetPosition()[0]
            << std::endl;

  std::cout << "Simulation completed successfully!" << std::endl;
  return 0;
}

}  // namespace bdm

#endif  // REPULSIONTEST_H_
