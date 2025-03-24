#include <art/unicode/writer.hxx>

#include <art/validation/main.hxx>

#include <string>

VALIDATION_TEST(test_XYZ)
{
  std::string str;
  art::unicode::string_writer_t writer{str};
  writer.write('X');
  writer.write('Y');
  writer.write('Z');

  VALIDATION_ASSERT_EQUAL(str, "XYZ");
}

int
main(int argc, char* argv[])
{
  return art::validation::main(argc, argv);
}
