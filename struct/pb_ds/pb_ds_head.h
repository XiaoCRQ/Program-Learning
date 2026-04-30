#include "../../t_head.h"
#include "bits/extc++.h"
using namespace __gnu_pbds;

// tag list
// rb_tree_tag == 红黑树
// splay_tree_tag == splay树
// ov_tree_tag == AVL树
//
// node_update list
// tree_order_statistics_node_update == 提供 find_by_order() | order_of_key()
// null_tree_policy == nothing

template <typename T>
using pb_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename A, typename B>
using pb_map =
    tree<A, B, less<A>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename A, typename B = null_type>
using pb_trie = trie<A,
                     B,
                     trie_string_access_traits<A>,
                     pat_trie_tag,
                     trie_prefix_search_node_update>;
template <typename A, typename B = null_type>
using pb_hash = gp_hash_table<A, B, chash>;

template <typename T>
using pb_heap = __gnu_pbds::priority_queue<T, less<T>, pairing_heap_tag>;
