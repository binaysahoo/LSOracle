/* mockturtle: C++ logic network library
 * Copyright (C) 2018  EPFL
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

/*!
  \file traits.hpp
  \brief Type traits and checkers for the network interface

  \author Mathias Soeken
*/

#pragma once

#include <type_traits>

#include <kitty/dynamic_truth_table.hpp>
#include <kitty/traits.hpp>

namespace mockturtle
{

template<typename Ntk>
using signal = typename Ntk::signal;

template<typename Ntk>
using node = typename Ntk::node;

template<class Ntk, class = void>
struct is_network_type : std::false_type
{
};

template<class Ntk>
struct is_network_type<Ntk, std::enable_if_t<
                                std::is_constructible_v<signal<Ntk>, node<Ntk>>,
                                std::void_t<signal<Ntk>,
                                            node<Ntk>,
                                            typename Ntk::storage,
                                            decltype( Ntk::max_fanin_size ),
                                            decltype( Ntk::min_fanin_size )>>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool is_network_type_v = is_network_type<Ntk>::value;

#pragma region is_topologically_sorted
template<class Ntk, class = void>
struct is_topologically_sorted : std::false_type
{
};

template<class Ntk>
struct is_topologically_sorted<Ntk, std::enable_if_t<Ntk::is_topologically_sorted, std::void_t<decltype( Ntk::is_topologically_sorted )>>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool is_topologically_sorted_v = is_topologically_sorted<Ntk>::value;
#pragma endregion

#pragma region has_get_constant
template<class Ntk, class = void>
struct has_get_constant : std::false_type
{
};

template<class Ntk>
struct has_get_constant<Ntk, std::void_t<decltype( std::declval<Ntk>().get_constant( bool() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_get_constant_v = has_get_constant<Ntk>::value;
#pragma endregion

#pragma region has_create_pi
template<class Ntk, class = void>
struct has_create_pi : std::false_type
{
};

template<class Ntk>
struct has_create_pi<Ntk, std::void_t<decltype( std::declval<Ntk>().create_pi( std::string() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_pi_v = has_create_pi<Ntk>::value;
#pragma endregion

#pragma region has_create_po
template<class Ntk, class = void>
struct has_create_po : std::false_type
{
};

template<class Ntk>
struct has_create_po<Ntk, std::void_t<decltype( std::declval<Ntk>().create_po( std::declval<signal<Ntk>>(), std::string() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_po_v = has_create_po<Ntk>::value;
#pragma endregion

#pragma region has_is_constant
template<class Ntk, class = void>
struct has_is_constant : std::false_type
{
};

template<class Ntk>
struct has_is_constant<Ntk, std::void_t<decltype( std::declval<Ntk>().is_constant( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_is_constant_v = has_is_constant<Ntk>::value;
#pragma endregion

#pragma region has_is_pi
template<class Ntk, class = void>
struct has_is_pi : std::false_type
{
};

template<class Ntk>
struct has_is_pi<Ntk, std::void_t<decltype( std::declval<Ntk>().is_pi( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_is_pi_v = has_is_pi<Ntk>::value;
#pragma endregion

#pragma region has_constant_value
template<class Ntk, class = void>
struct has_constant_value : std::false_type
{
};

template<class Ntk>
struct has_constant_value<Ntk, std::void_t<decltype( std::declval<Ntk>().constant_value( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_constant_value_v = has_constant_value<Ntk>::value;
#pragma endregion

#pragma region has_create_buf
template<class Ntk, class = void>
struct has_create_buf : std::false_type
{
};

template<class Ntk>
struct has_create_buf<Ntk, std::void_t<decltype( std::declval<Ntk>().create_buf( std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_buf_v = has_create_buf<Ntk>::value;
#pragma endregion

#pragma region has_create_not
template<class Ntk, class = void>
struct has_create_not : std::false_type
{
};

template<class Ntk>
struct has_create_not<Ntk, std::void_t<decltype( std::declval<Ntk>().create_not( std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_not_v = has_create_not<Ntk>::value;
#pragma endregion

#pragma region has_create_and
template<class Ntk, class = void>
struct has_create_and : std::false_type
{
};

template<class Ntk>
struct has_create_and<Ntk, std::void_t<decltype( std::declval<Ntk>().create_and( std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_and_v = has_create_and<Ntk>::value;
#pragma endregion

#pragma region has_create_nand
template<class Ntk, class = void>
struct has_create_nand : std::false_type
{
};

template<class Ntk>
struct has_create_nand<Ntk, std::void_t<decltype( std::declval<Ntk>().create_nand( std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_nand_v = has_create_nand<Ntk>::value;
#pragma endregion

#pragma region has_create_or
template<class Ntk, class = void>
struct has_create_or : std::false_type
{
};

template<class Ntk>
struct has_create_or<Ntk, std::void_t<decltype( std::declval<Ntk>().create_or( std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_or_v = has_create_or<Ntk>::value;
#pragma endregion

#pragma region has_create_nor
template<class Ntk, class = void>
struct has_create_nor : std::false_type
{
};

template<class Ntk>
struct has_create_nor<Ntk, std::void_t<decltype( std::declval<Ntk>().create_nor( std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_nor_v = has_create_nor<Ntk>::value;
#pragma endregion

#pragma region has_create_lt
template<class Ntk, class = void>
struct has_create_lt : std::false_type
{
};

template<class Ntk>
struct has_create_lt<Ntk, std::void_t<decltype( std::declval<Ntk>().create_lt( std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_lt_v = has_create_lt<Ntk>::value;
#pragma endregion

#pragma region has_create_le
template<class Ntk, class = void>
struct has_create_le : std::false_type
{
};

template<class Ntk>
struct has_create_le<Ntk, std::void_t<decltype( std::declval<Ntk>().create_le( std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_le_v = has_create_le<Ntk>::value;
#pragma endregion

#pragma region has_create_gt
template<class Ntk, class = void>
struct has_create_gt : std::false_type
{
};

template<class Ntk>
struct has_create_gt<Ntk, std::void_t<decltype( std::declval<Ntk>().create_gt( std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_gt_v = has_create_gt<Ntk>::value;
#pragma endregion

#pragma region has_create_ge
template<class Ntk, class = void>
struct has_create_ge : std::false_type
{
};

template<class Ntk>
struct has_create_ge<Ntk, std::void_t<decltype( std::declval<Ntk>().create_ge( std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_ge_v = has_create_ge<Ntk>::value;
#pragma endregion

#pragma region has_create_xor
template<class Ntk, class = void>
struct has_create_xor : std::false_type
{
};

template<class Ntk>
struct has_create_xor<Ntk, std::void_t<decltype( std::declval<Ntk>().create_xor( std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_xor_v = has_create_xor<Ntk>::value;
#pragma endregion

#pragma region has_create_xnor
template<class Ntk, class = void>
struct has_create_xnor : std::false_type
{
};

template<class Ntk>
struct has_create_xnor<Ntk, std::void_t<decltype( std::declval<Ntk>().create_xnor( std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_xnor_v = has_create_xnor<Ntk>::value;
#pragma endregion

#pragma region has_create_maj
template<class Ntk, class = void>
struct has_create_maj : std::false_type
{
};

template<class Ntk>
struct has_create_maj<Ntk, std::void_t<decltype( std::declval<Ntk>().create_maj( std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_maj_v = has_create_maj<Ntk>::value;
#pragma endregion

#pragma region has_create_ite
template<class Ntk, class = void>
struct has_create_ite : std::false_type
{
};

template<class Ntk>
struct has_create_ite<Ntk, std::void_t<decltype( std::declval<Ntk>().create_ite( std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>(), std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_ite_v = has_create_ite<Ntk>::value;
#pragma endregion

#pragma region has_create_node
template<class Ntk, class = void>
struct has_create_node : std::false_type
{
};

template<class Ntk>
struct has_create_node<Ntk, std::void_t<decltype( std::declval<Ntk>().create_node( std::declval<std::vector<signal<Ntk>>>(), std::declval<kitty::dynamic_truth_table>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_create_node_v = has_create_node<Ntk>::value;
#pragma endregion

#pragma region has_clone_node
template<class Ntk, class = void>
struct has_clone_node : std::false_type
{
};

template<class Ntk>
struct has_clone_node<Ntk, std::void_t<decltype( std::declval<Ntk>().clone_node( std::declval<Ntk>(), std::declval<node<Ntk>>(), std::declval<std::vector<signal<Ntk>>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_clone_node_v = has_clone_node<Ntk>::value;
#pragma endregion

#pragma region has_size
template<class Ntk, class = void>
struct has_size : std::false_type
{
};

template<class Ntk>
struct has_size<Ntk, std::void_t<decltype( std::declval<Ntk>().size() )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_size_v = has_size<Ntk>::value;
#pragma endregion

#pragma region has_substitute_node
template<class Ntk, class = void>
struct has_substitute_node : std::false_type
{
};

template<class Ntk>
struct has_substitute_node<Ntk, std::void_t<decltype( std::declval<Ntk>().substitute_node( std::declval<node<Ntk>>(), std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_substitute_node_v = has_substitute_node<Ntk>::value;
#pragma endregion

#pragma region has_num_pis
template<class Ntk, class = void>
struct has_num_pis : std::false_type
{
};

template<class Ntk>
struct has_num_pis<Ntk, std::void_t<decltype( std::declval<Ntk>().num_pis() )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_num_pis_v = has_num_pis<Ntk>::value;
#pragma endregion

#pragma region has_num_pos
template<class Ntk, class = void>
struct has_num_pos : std::false_type
{
};

template<class Ntk>
struct has_num_pos<Ntk, std::void_t<decltype( std::declval<Ntk>().num_pos() )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_num_pos_v = has_num_pos<Ntk>::value;
#pragma endregion

#pragma region has_num_gates
template<class Ntk, class = void>
struct has_num_gates : std::false_type
{
};

template<class Ntk>
struct has_num_gates<Ntk, std::void_t<decltype( std::declval<Ntk>().num_gates() )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_num_gates_v = has_num_gates<Ntk>::value;
#pragma endregion

#pragma region has_fanin_size
template<class Ntk, class = void>
struct has_fanin_size : std::false_type
{
};

template<class Ntk>
struct has_fanin_size<Ntk, std::void_t<decltype( std::declval<Ntk>().fanin_size( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_fanin_size_v = has_fanin_size<Ntk>::value;
#pragma endregion

#pragma region has_fanout_size
template<class Ntk, class = void>
struct has_fanout_size : std::false_type
{
};

template<class Ntk>
struct has_fanout_size<Ntk, std::void_t<decltype( std::declval<Ntk>().fanout_size( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_fanout_size_v = has_fanout_size<Ntk>::value;
#pragma endregion

#pragma region has_depth
template<class Ntk, class = void>
struct has_depth : std::false_type
{
};

template<class Ntk>
struct has_depth<Ntk, std::void_t<decltype( std::declval<Ntk>().depth() )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_depth_v = has_depth<Ntk>::value;
#pragma endregion

#pragma region has_level
template<class Ntk, class = void>
struct has_level : std::false_type
{
};

template<class Ntk>
struct has_level<Ntk, std::void_t<decltype( std::declval<Ntk>().level( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_level_v = has_level<Ntk>::value;
#pragma endregion

#pragma region has_is_maj
template<class Ntk, class = void>
struct has_is_maj : std::false_type
{
};

template<class Ntk>
struct has_is_maj<Ntk, std::void_t<decltype( std::declval<Ntk>().is_maj( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_is_maj_v = has_is_maj<Ntk>::value;
#pragma endregion

#pragma region has_is_ite
template<class Ntk, class = void>
struct has_is_ite : std::false_type
{
};

template<class Ntk>
struct has_is_ite<Ntk, std::void_t<decltype( std::declval<Ntk>().is_ite( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_is_ite_v = has_is_ite<Ntk>::value;
#pragma endregion

#pragma region has_node_function
template<class Ntk, class = void>
struct has_node_function : std::false_type
{
};

template<class Ntk>
struct has_node_function<Ntk, std::void_t<decltype( std::declval<Ntk>().node_function( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_node_function_v = has_node_function<Ntk>::value;
#pragma endregion

#pragma region has_get_node
template<class Ntk, class = void>
struct has_get_node : std::false_type
{
};

template<class Ntk>
struct has_get_node<Ntk, std::void_t<decltype( std::declval<Ntk>().get_node( std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_get_node_v = has_get_node<Ntk>::value;
#pragma endregion

#pragma region has_make_signal
template<class Ntk, class = void>
struct has_make_signal : std::false_type
{
};

template<class Ntk>
struct has_make_signal<Ntk, std::void_t<decltype( std::declval<Ntk>().make_signal( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_make_signal_v = has_make_signal<Ntk>::value;
#pragma endregion

#pragma region has_is_complemented
template<class Ntk, class = void>
struct has_is_complemented : std::false_type
{
};

template<class Ntk>
struct has_is_complemented<Ntk, std::void_t<decltype( std::declval<Ntk>().is_complemented( std::declval<signal<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_is_complemented_v = has_is_complemented<Ntk>::value;
#pragma endregion

#pragma region has_node_to_index
template<class Ntk, class = void>
struct has_node_to_index : std::false_type
{
};

template<class Ntk>
struct has_node_to_index<Ntk, std::void_t<decltype( std::declval<Ntk>().node_to_index( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_node_to_index_v = has_node_to_index<Ntk>::value;
#pragma endregion

#pragma region has_index_to_node
template<class Ntk, class = void>
struct has_index_to_node : std::false_type
{
};

template<class Ntk>
struct has_index_to_node<Ntk, std::void_t<decltype( std::declval<Ntk>().index_to_node( uint32_t() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_index_to_node_v = has_index_to_node<Ntk>::value;
#pragma endregion

#pragma region has_foreach_node
template<class Ntk, class = void>
struct has_foreach_node : std::false_type
{
};

template<class Ntk>
struct has_foreach_node<Ntk, std::void_t<decltype( std::declval<Ntk>().foreach_node( std::declval<void( node<Ntk>, uint32_t )>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_foreach_node_v = has_foreach_node<Ntk>::value;
#pragma endregion

#pragma region has_foreach_pi
template<class Ntk, class = void>
struct has_foreach_pi : std::false_type
{
};

template<class Ntk>
struct has_foreach_pi<Ntk, std::void_t<decltype( std::declval<Ntk>().foreach_pi( std::declval<void( node<Ntk>, uint32_t )>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_foreach_pi_v = has_foreach_pi<Ntk>::value;
#pragma endregion

#pragma region has_foreach_po
template<class Ntk, class = void>
struct has_foreach_po : std::false_type
{
};

template<class Ntk>
struct has_foreach_po<Ntk, std::void_t<decltype( std::declval<Ntk>().foreach_po( std::declval<void( signal<Ntk>, uint32_t )>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_foreach_po_v = has_foreach_po<Ntk>::value;
#pragma endregion

#pragma region has_foreach_gate
template<class Ntk, class = void>
struct has_foreach_gate : std::false_type
{
};

template<class Ntk>
struct has_foreach_gate<Ntk, std::void_t<decltype( std::declval<Ntk>().foreach_gate( std::declval<void( node<Ntk>, uint32_t )>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_foreach_gate_v = has_foreach_gate<Ntk>::value;
#pragma endregion

#pragma region has_foreach_fanin
template<class Ntk, class = void>
struct has_foreach_fanin : std::false_type
{
};

template<class Ntk>
struct has_foreach_fanin<Ntk, std::void_t<decltype( std::declval<Ntk>().foreach_fanin( std::declval<node<Ntk>>(), std::declval<void( signal<Ntk>, uint32_t )>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_foreach_fanin_v = has_foreach_fanin<Ntk>::value;
#pragma endregion

#pragma region has_foreach_parent
template<class Ntk, class = void>
struct has_foreach_parent : std::false_type
{
};

template<class Ntk>
struct has_foreach_parent<Ntk, std::void_t<decltype( std::declval<Ntk>().foreach_parent( std::declval<node<Ntk>>(), std::declval<void( node<Ntk>, uint32_t )>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_foreach_parent_v = has_foreach_parent<Ntk>::value;
#pragma endregion

#pragma region has_compute
template<class Ntk, typename T, class = void>
struct has_compute : std::false_type
{
};

template<class Ntk, typename T>
struct has_compute<Ntk, T, std::void_t<decltype( std::declval<Ntk>().compute( std::declval<node<Ntk>>(), std::begin( std::vector<T>() ), std::end( std::vector<T>() ) ) )>> : std::true_type
{
};

template<class Ntk, typename T>
inline constexpr bool has_compute_v = has_compute<Ntk, T>::value;
#pragma endregion

#pragma region has_has_mapping
template<class Ntk, class = void>
struct has_has_mapping : std::false_type
{
};

template<class Ntk>
struct has_has_mapping<Ntk, std::void_t<decltype( std::declval<Ntk>().has_mapping() )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_has_mapping_v = has_has_mapping<Ntk>::value;
#pragma endregion

#pragma region has_is_cell_root
template<class Ntk, class = void>
struct has_is_cell_root : std::false_type
{
};

template<class Ntk>
struct has_is_cell_root<Ntk, std::void_t<decltype( std::declval<Ntk>().is_cell_root( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_is_cell_root_v = has_is_cell_root<Ntk>::value;
#pragma endregion

#pragma region has_clear_mapping
template<class Ntk, class = void>
struct has_clear_mapping : std::false_type
{
};

template<class Ntk>
struct has_clear_mapping<Ntk, std::void_t<decltype( std::declval<Ntk>().clear_mapping() )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_clear_mapping_v = has_clear_mapping<Ntk>::value;
#pragma endregion

#pragma region has_num_cells
template<class Ntk, class = void>
struct has_num_cells : std::false_type
{
};

template<class Ntk>
struct has_num_cells<Ntk, std::void_t<decltype( std::declval<Ntk>().num_cells() )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_num_cells_v = has_num_cells<Ntk>::value;
#pragma endregion

#pragma region has_add_to_mapping
template<class Ntk, class = void>
struct has_add_to_mapping : std::false_type
{
};

template<class Ntk>
struct has_add_to_mapping<Ntk, std::void_t<decltype( std::declval<Ntk>().add_to_mapping( std::declval<node<Ntk>>(), std::begin( std::vector<node<Ntk>>() ), std::end( std::vector<node<Ntk>>() ) ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_add_to_mapping_v = has_add_to_mapping<Ntk>::value;
#pragma endregion

#pragma region has_remove_from_mapping
template<class Ntk, class = void>
struct has_remove_from_mapping : std::false_type
{
};

template<class Ntk>
struct has_remove_from_mapping<Ntk, std::void_t<decltype( std::declval<Ntk>().remove_from_mapping( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_remove_from_mapping_v = has_remove_from_mapping<Ntk>::value;
#pragma endregion

#pragma region has_cell_function
template<class Ntk, class = void>
struct has_cell_function : std::false_type
{
};

template<class Ntk>
struct has_cell_function<Ntk, std::void_t<decltype( std::declval<Ntk>().cell_function( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_cell_function_v = has_cell_function<Ntk>::value;
#pragma endregion

#pragma region has_set_cell_function
template<class Ntk, class = void>
struct has_set_cell_function : std::false_type
{
};

template<class Ntk>
struct has_set_cell_function<Ntk, std::void_t<decltype( std::declval<Ntk>().set_cell_function( std::declval<node<Ntk>>(), std::declval<kitty::dynamic_truth_table>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_set_cell_function_v = has_set_cell_function<Ntk>::value;
#pragma endregion

#pragma region has_foreach_cell_fanin
template<class Ntk, class = void>
struct has_foreach_cell_fanin : std::false_type
{
};

template<class Ntk>
struct has_foreach_cell_fanin<Ntk, std::void_t<decltype( std::declval<Ntk>().foreach_cell_fanin( std::declval<node<Ntk>>(), std::declval<void( node<Ntk>, uint32_t )>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_foreach_cell_fanin_v = has_foreach_cell_fanin<Ntk>::value;
#pragma endregion

#pragma region has_clear_values
template<class Ntk, class = void>
struct has_clear_values : std::false_type
{
};

template<class Ntk>
struct has_clear_values<Ntk, std::void_t<decltype( std::declval<Ntk>().clear_values() )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_clear_values_v = has_clear_values<Ntk>::value;
#pragma endregion

#pragma region has_value
template<class Ntk, class = void>
struct has_value : std::false_type
{
};

template<class Ntk>
struct has_value<Ntk, std::void_t<decltype( std::declval<Ntk>().value( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_value_v = has_value<Ntk>::value;
#pragma endregion

#pragma region set_value
template<class Ntk, class = void>
struct has_set_value : std::false_type
{
};

template<class Ntk>
struct has_set_value<Ntk, std::void_t<decltype( std::declval<Ntk>().set_value( std::declval<node<Ntk>>(), uint32_t() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_set_value_v = has_set_value<Ntk>::value;
#pragma endregion

#pragma region incr_value
template<class Ntk, class = void>
struct has_incr_value : std::false_type
{
};

template<class Ntk>
struct has_incr_value<Ntk, std::void_t<decltype( std::declval<Ntk>().incr_value( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_incr_value_v = has_incr_value<Ntk>::value;
#pragma endregion

#pragma region decr_value
template<class Ntk, class = void>
struct has_decr_value : std::false_type
{
};

template<class Ntk>
struct has_decr_value<Ntk, std::void_t<decltype( std::declval<Ntk>().decr_value( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_decr_value_v = has_decr_value<Ntk>::value;
#pragma endregion

#pragma region has_clear_visited
template<class Ntk, class = void>
struct has_clear_visited : std::false_type
{
};

template<class Ntk>
struct has_clear_visited<Ntk, std::void_t<decltype( std::declval<Ntk>().clear_visited() )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_clear_visited_v = has_clear_visited<Ntk>::value;
#pragma endregion

#pragma region has_visited
template<class Ntk, class = void>
struct has_visited : std::false_type
{
};

template<class Ntk>
struct has_visited<Ntk, std::void_t<decltype( std::declval<Ntk>().visited( std::declval<node<Ntk>>() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_visited_v = has_visited<Ntk>::value;
#pragma endregion

#pragma region set_visited
template<class Ntk, class = void>
struct has_set_visited : std::false_type
{
};

template<class Ntk>
struct has_set_visited<Ntk, std::void_t<decltype( std::declval<Ntk>().set_visited( std::declval<node<Ntk>>(), uint32_t() ) )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_set_visited_v = has_set_visited<Ntk>::value;
#pragma endregion

#pragma region has_update
template<class Ntk, class = void>
struct has_update : std::false_type
{
};

template<class Ntk>
struct has_update<Ntk, std::void_t<decltype( std::declval<Ntk>().update() )>> : std::true_type
{
};

template<class Ntk>
inline constexpr bool has_update_v = has_update<Ntk>::value;
#pragma endregion

/*! \brief SFINAE based on iterator type (for compute functions).
 */
template<typename Iterator, typename T>
using iterates_over_t = std::enable_if_t<std::is_same_v<typename Iterator::value_type, T>, T>;

/*! \brief SFINAE based on iterator type for truth tables (for compute functions).
 */
template<typename Iterator>
using iterates_over_truth_table_t = std::enable_if_t<kitty::is_truth_table<typename Iterator::value_type>::value, typename Iterator::value_type>;

} /* namespace mockturtle */