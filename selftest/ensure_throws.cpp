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
    test_id_throws = 1
};
}

namespace tut
{
  /**
   * Testing ensure_throws() method.
   */
  struct ensure_throws_test
  {
      virtual ~ensure_throws_test()
      {
      }
  };

  typedef test_group<ensure_throws_test> tf;
  typedef tf::object object;
  tf ensure_throws_test("ensure_throws c++11 fn");

  template<>
  template<>
  void object::test<test_id_throws>()
  {
      auto is_invoked = false; 
      auto is_thrown = false;
      try {
        is_invoked = false;
        ensure_throws<failure>
          ("Should fail, there was no exception"
           , [&is_invoked]() {
            is_invoked = true;
          });
      } catch (failure const &f) {
        is_thrown = true;
      } catch (...) {
        fail("Thrown exception other than failure");
      }
      ensure("First ensure eq should be invoked", is_invoked);
      ensure("failure is not thrown", is_thrown);
      is_invoked = false;
      ensure_throws<failure>("Expecting failure", [&is_invoked]() {
          is_invoked = true;
          ensure(false);
        });
      ensure("Wrong eq was not invoked", is_invoked);
  }

}
