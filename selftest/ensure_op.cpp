#include <tut/tut.hpp>
#include <tut/tut_macros.hpp>
#include <string>
#include <sstream>
#include <stdexcept>

using std::string;
using std::ostringstream;
using std::runtime_error;

namespace {
enum test_ids {
    test_id_eq = 1
    , test_id_ne
    , test_id_ge
    , test_id_le
    , test_id_lt
    , test_id_gt
};
}

namespace tut
{
  /**
   * Testing ensure_op() method.
   */
  struct ensure_op_test
  {
      virtual ~ensure_op_test()
      {
      }
  };

  typedef test_group<ensure_op_test> tf;
  typedef tf::object object;
  tf ensure_op_test("ensure_op");

  template<>
  template<>
  void object::test<test_id_eq>()
  {
      ensure_eq("Eq int", 1, 1);
      ensure_eq("Eq str", "a", "a");
      ensure_throws<failure>
        ("ensure_eq should fail here", []() {
          ensure_eq("Eq int", 1, 2);
        });
  }

  template<>
  template<>
  void object::test<test_id_ne>()
  {
      ensure_ne("Eq int", 1, 3);
      ensure_ne("Eq str", "a", "b");
      ensure_throws<failure>
        ("ensure_ne should fail here", []() {
          ensure_ne("ne int", 1, 1);
        });
  }

  template<>
  template<>
  void object::test<test_id_ge>()
  {
      ensure_ge("ge int", 1, 1);
      ensure_ge("ge int", 2, 1);
      ensure_ge("ge str", "a", "a");
      ensure_ge("ge str", "b", "a");
      ensure_throws<failure>
        ("ensure_ge should fail here", []() {
          ensure_ge("ge int", 1, 2);
        });
  }

  template<>
  template<>
  void object::test<test_id_le>()
  {
      ensure_le("le int", 1, 1);
      ensure_le("le int", 1, 2);
      ensure_le("le str", "a", "a");
      ensure_le("le str", "a", "b");
      ensure_throws<failure>
        ("ensure_le should fail here", []() {
          ensure_le("le int", 2, 1);
        });
  }

  template<>
  template<>
  void object::test<test_id_lt>()
  {
      ensure_lt("lt int", 0, 1);
      ensure_lt("lt int", -1, 1);
      ensure_lt("lt str", "a", "b");
      ensure_throws<failure>
        ("ensure_lt should fail here", []() {
          ensure_lt("lt int", 2, 1);
        });
  }

  template<>
  template<>
  void object::test<test_id_gt>()
  {
      ensure_gt("gt int", 1, 0);
      ensure_gt("gt int", 1, -1);
      ensure_gt("gt str", "b", "a");
      ensure_throws<failure>
        ("ensure_gt should fail here", []() {
          ensure_gt("gt int", 1, 2);
        });
  }

}
