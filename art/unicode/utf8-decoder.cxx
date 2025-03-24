#include <art/unicode/utf8-decoder.hxx>

namespace art::unicode
{

  utf8_decoder_t::
  utf8_decoder_t(reader_t& reader)
    : _reader{reader}
  {}

  uint32_t
  utf8_decoder_t::
  decode()
  {
    if (at_end()) {
      return replacement_character;
    }

    uint32_t c1 = _reader.advance();

    // 1 byte (valid: 0 <= value <= 0x7f)
    //
    if (c1 <= 0x7f) {
      return c1;
    }

    if (at_end()) {
      return replacement_character;
    }

    std::uint32_t c2 = _reader.advance();

    // 2 bytes (valid: 0x80 <= value <= 0x7ff)
    //
    if (c1 <= 0b11011111) {
      std::uint32_t c = ((c1 & 0b00011111) << 6) | (c2 & 0b00111111);

      // Overlong protection.
      //
      if (c < 0x80) {
        return replacement_character;
      }

      return c;
    }

    if (at_end()) {
      return replacement_character;
    }

    std::uint32_t c3 = _reader.advance();

    // 3 bytes (valid: 0x800 <= value <= 0xffff)
    //
    if (c1 <= 0b11101111) {
      std::uint32_t c = ((c1 & 0b00001111) << 12) | ((c2 & 0b00111111) << 6) | (c3 & 0b00111111);

      // Overlong protection.
      //
      if (c < 0x800) {
        return replacement_character;
      }

      return c;
    }

    if (at_end()) {
      return replacement_character;
    }

    std::uint32_t c4 = _reader.advance();

    // 4 bytes (valid: 0x10000 <= value <= 0x10ffff)
    //
    if (c1 <= 0b11110111) {
      std::uint32_t c = ((c1 & 0b00000111) << 18) | ((c2 & 0b00111111) << 12) |
                        ((c3 & 0b00111111) << 6) | (c4 & 0b00111111);

      // Overlong protection.
      //
      if (c < 0x10000) {
        return replacement_character;
      }

      // Overflow protection.
      //
      if (0x10ffff < c) {
        return replacement_character;
      }

      return c;
    }

    // Invalid.
    //
    return replacement_character;
  }

  bool
  utf8_decoder_t::
  at_end()
  {
    return _reader.at_end();
  }

} // namespace art::unicode
