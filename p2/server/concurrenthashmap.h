#include <cassert>
#include <functional>
#include <iostream>
#include <list>
#include <mutex>
#include <string>
#include <vector>

#include "map.h"

/// ConcurrentHashMap is a concurrent implementation of the Map interface (a
/// Key/Value store).  It is implemented as a vector of buckets, with one lock
/// per bucket.  Since the number of buckets is fixed, performance can suffer if
/// the thread count is high relative to the number of buckets.  Furthermore,
/// the asymptotic guarantees of this data structure are dependent on the
/// quality of the bucket implementation.  If a vector is used within the bucket
/// to store key/value pairs, then the guarantees will be poor if the key range
/// is large relative to the number of buckets.  If an unordered_map is used,
/// then the asymptotic guarantees should be strong.
///
/// The ConcurrentHashMap is templated on the Key and Value types.
///
/// This map uses std::hash to map keys to positions in the vector.  A
/// production map should use something better.
///
/// This map provides strong consistency guarantees: every operation uses
/// two-phase locking (2PL), and the lambda parameters to methods enable nesting
/// of 2PL operations across maps.
///
/// @param K The type of the keys in this map
/// @param V The type of the values in this map
template <typename K, typename V> class ConcurrentHashMap : public Map<K, V> {

public:
  /// Construct by specifying the number of buckets it should have
  ///
  /// @param _buckets The number of buckets
  ConcurrentHashMap(size_t) {
    std::cout << "ConcurrentHashMap::ConcurrentHashMap() is not implemented";
  }

  /// Destruct the ConcurrentHashMap
  virtual ~ConcurrentHashMap() {
    std::cout << "ConcurrentHashMap::~ConcurrentHashMap() is not implemented";
  }

  /// Clear the map.  This operation needs to use 2pl
  virtual void clear() {
    std::cout << "ConcurrentHashMap::clear() is not implemented";
  }

  /// Insert the provided key/value pair only if there is no mapping for the key
  /// yet.
  ///
  /// @param key        The key to insert
  /// @param val        The value to insert
  /// @param on_success Code to run if the insertion succeeds
  ///
  /// @return true if the key/value was inserted, false if the key already
  ///         existed in the table
  virtual bool insert(K , V , std::function<void()>) {
    std::cout << "ConcurrentHashMap::insert() is not implemented";
    return false;
  }

  /// Insert the provided key/value pair if there is no mapping for the key yet.
  /// If there is a key, then update the mapping by replacing the old value with
  /// the provided value
  ///
  /// @param key    The key to upsert
  /// @param val    The value to upsert
  /// @param on_ins Code to run if the upsert succeeds as an insert
  /// @param on_upd Code to run if the upsert succeeds as an update
  ///
  /// @return true if the key/value was inserted, false if the key already
  ///         existed in the table and was thus updated instead
  virtual bool upsert(K , V , std::function<void()> ,
                      std::function<void()> ) {
    std::cout << "ConcurrentHashMap::upsert() is not implemented";
    return false;
  }

  /// Apply a function to the value associated with a given key.  The function
  /// is allowed to modify the value.
  ///
  /// @param key The key whose value will be modified
  /// @param f   The function to apply to the key's value
  /// @param on_success Code to run if the key is found and the function is applied, 
  /// but before unlocking...
  ///
  /// @return true if the key existed and the function was applied, false
  ///         otherwise
  virtual bool do_with(K , std::function<void(V &)>, std::function<void()> ) {
    std::cout << "ConcurrentHashMap::do_with() is not implemented";
    return false;
  }

  /// Apply a function to the value associated with a given key.  The function
  /// is not allowed to modify the value.
  ///
  /// @param key The key whose value will be modified
  /// @param f   The function to apply to the key's value
  /// @param on_success Code to run if the key is found and the function is applied, 
  /// but before unlocking...
  ///
  /// @return true if the key existed and the function was applied, false
  ///         otherwise
  virtual bool do_with_readonly(K , std::function<void(const V &)>, std::function<void()> ) {
    std::cout << "ConcurrentHashMap::do_with_readonly() is not implemented";
    return false;
  }

  /// Remove the mapping from a key to its value
  ///
  /// @param key        The key whose mapping should be removed
  /// @param on_success Code to run if the remove succeeds
  ///
  /// @return true if the key was found and the value unmapped, false otherwise
  virtual bool remove(K , std::function<void()> ) {
    std::cout << "ConcurrentHashMap::remove() is not implemented";
    return false;
  }

  /// Apply a function to every key/value pair in the map.  Note that the
  /// function is not allowed to modify keys or values.
  ///
  /// @param f    The function to apply to each key/value pair
  /// @param then A function to run when this is done, but before unlocking...
  ///             useful for 2pl
  virtual void do_all_readonly(std::function<void(const K, const V &)> ,
                               std::function<void()> ) {
    std::cout << "ConcurrentHashMap::do_all_readonly() is not implemented";
  }
};
