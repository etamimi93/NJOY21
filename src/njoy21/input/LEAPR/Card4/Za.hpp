struct Za {
  using Value_t = long;
  static std::string name() { return "za"; }
  static std::string description(){
    return
      "The za argument is calculated to be 1000 * Z + A, where Z and A are\n"
      "atomic number and the atomic mass number, respecively, for the\n"
      "principle scatterer.";
  }
  static bool verify( const Value_t& z ){ return z > 1000 and z < 200000 ; }
};
