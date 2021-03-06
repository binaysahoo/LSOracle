Network simulation
------------------

**Header:** ``mockturtle/algorithms/simulation.hpp``

**Examples**

Simulate a Boolean input assignment.

.. code-block:: c++

   aig_network aig = ...;

   std::vector<bool> assignment( aig.num_pis() );
   assignment[0] = true;
   assignment[1] = false;
   assignment[2] = false;
   ...

   default_simulator<bool> sim( assignment );
   const auto values = simulate<bool>( aig, sim );

   ntk.foreach_po( [&]( auto const&, auto i ) {
     std::cout << fmt::format( "output {} has simulation value {}\n", i, values[i] );
   } );

Complete simulation with truth tables.

.. code-block:: c++

   aig_network aig = ...;

   default_simulator<kitty::dynamic_truth_table> sim( aig.num_pis() );
   const auto tts = simulate<kitty::dynamic_truth_table>( aig, sim );

   ntk.foreach_po( [&]( auto const&, auto i ) {
     std::cout << fmt::format( "truth table of output {} is {}\n", i, kitty::to_hex( tts[i] ) );
   } );

Simulate values for all nodes.

.. code-block:: c++

   aig_network aig = ...;

   default_simulator<kitty::dynamic_truth_table> sim( aig.num_pis() );
   const auto tts = simulate_nodes<kitty::dynamic_truth_table>( aig, sim );

   ntk.foreach_node( [&]( auto const& n, auto i ) {
     std::cout << fmt::format( "truth table of node {} is {}\n", i, tts[n] );
   } );

.. doxygenfunction:: mockturtle::simulate
  
.. doxygenfunction:: mockturtle::simulate_nodes

Simulators
~~~~~~~~~~

The following simulators are implemented:

* ``mockturtle::default_simulator<bool>``: This simulator simulates Boolean
  values.  A vector with assignments for each primary input must be passed to
  the constructor.
* ``mockturtle::default_simulator<kitty::static_truth_table<NumVars>>``: This
  simulator simulates truth tables.  Each primary input is assigned the
  projection function according to the index.  The number of variables must be
  known at compile time.
* ``mockturtle::default_simulator<kitty::dynamic_truth_table>``: This simulator
  simulates truth tables.  Each primary input is assigned the projection
  function according to the index.  The number of variables be passed to the
  constructor of the simulator.