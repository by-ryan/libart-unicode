#include <art/unicode/writer.hxx>
#include <art/unicode/utf8-encoder.hxx>

#include <art/validation/main.hxx>

#include <string>


VALIDATION_TEST(test_1)
{
  std::string str;

  art::unicode::string_writer_t writer{str};
  art::unicode::utf8_encoder_t encoder{writer};
  encoder.encode(0);

  VALIDATION_ASSERT_EQUAL(str.size(), 1U);
  VALIDATION_ASSERT_EQUAL(str[0], 0);
}

VALIDATION_TEST(test_2)
{
  std::string str;

  art::unicode::string_writer_t writer{str};
  art::unicode::utf8_encoder_t encoder{writer};
  encoder.encode(0x7f);

  VALIDATION_ASSERT_EQUAL(str.size(), 1U);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[0], 0x7f);
}

VALIDATION_TEST(test_3)
{
  std::string str;

  art::unicode::string_writer_t writer{str};
  art::unicode::utf8_encoder_t encoder{writer};
  encoder.encode(0x80);

  VALIDATION_ASSERT_EQUAL(str.size(), 2U);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[0], 0xc2);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[1], 0x80);
}

VALIDATION_TEST(test_4)
{
  std::string str;

  art::unicode::string_writer_t writer{str};
  art::unicode::utf8_encoder_t encoder{writer};
  encoder.encode(0x7ff);

  VALIDATION_ASSERT_EQUAL(str.size(), 2U);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[0], 0xdf);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[1], 0xbf);
}

VALIDATION_TEST(test_5)
{
  std::string str;

  art::unicode::string_writer_t writer{str};
  art::unicode::utf8_encoder_t encoder{writer};
  encoder.encode(0x800);

  VALIDATION_ASSERT_EQUAL(str.size(), 3U);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[0], 0xe0);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[1], 0xa0);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[2], 0x80);
}

VALIDATION_TEST(test_6)
{
  std::string str;

  art::unicode::string_writer_t writer{str};
  art::unicode::utf8_encoder_t encoder{writer};
  encoder.encode(0xffff);

  VALIDATION_ASSERT_EQUAL(str.size(), 3U);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[0], 0xef);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[1], 0xbf);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[2], 0xbf);
}

VALIDATION_TEST(test_7)
{
  std::string str;

  art::unicode::string_writer_t writer{str};
  art::unicode::utf8_encoder_t encoder{writer};
  encoder.encode(0x10000);

  VALIDATION_ASSERT_EQUAL(str.size(), 4U);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[0], 0xf0);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[1], 0x90);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[2], 0x80);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[3], 0x80);
}

VALIDATION_TEST(test_8)
{
  std::string str;

  art::unicode::string_writer_t writer{str};
  art::unicode::utf8_encoder_t encoder{writer};
  encoder.encode(0x10ffff);

  VALIDATION_ASSERT_EQUAL(str.size(), 4U);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[0], 0xf4);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[1], 0x8f);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[2], 0xbf);
  VALIDATION_ASSERT_EQUAL((unsigned char)str[3], 0xbf);
}

int
main(int argc, char* argv[])
{
  return art::validation::main(argc, argv);
}
