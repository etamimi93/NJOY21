struct Nlev {
  using Value_t = int;
  
  static std::string name(){ return "nlev"; }
  static std::string description(){ 
    return
      "nlev defines the number of correlation matrix intervals to be used\n"
      "with Card2's icolor option.\n"
      "\n"
      "nlev must be an integer between 1 and 9, inclusively. nlev has a \n"
      "default value of 0. However, if the default value is used, then noi\n"
      "nlev input may be provided, thus invoking nlev default value of 6.";
  } 
  
  static bool verify( const Value_t& nlev ){
    return 0 < nlev and nlev < 10;
  }
};