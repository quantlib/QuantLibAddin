
#include "utils.hpp"
#include "init.hpp"//DELETEME
#include "FlyLib/FlyLib_Double.h"
#include <ql/time/date.hpp>
#include "qlo/conversions/conversions.hpp"
#include <string>
#include <algorithm>

std::vector<double> f1(FLYLIB_OPAQUE _in_params) {
  FlyLib_Multi in_params (_in_params);
  int nrows (in_params.num_rows ());
  int ncols (in_params.num_cols ());


    std::vector<double> ret;
if (ncols>1) return ret;
  for (int col = 0; col < ncols; col ++) {
    for (int row = 0; row < nrows; row++) {
      ACE_TString cur_name;
      if (in_params.get_cell (cur_name, row, col) == 0) {
         double d = FlyLib_Double::to_double (cur_name.c_str ());
            ret.push_back(d);
      }
    }
  }
    return ret;
}

std::vector<long> f2(FLYLIB_OPAQUE _in_params) {
  FlyLib_Multi in_params (_in_params);
  int nrows (in_params.num_rows ());
  int ncols (in_params.num_cols ());

    std::vector<long> ret;
if (ncols>1) return ret;
  for (int col = 0; col < ncols; col ++) {
    for (int row = 0; row < nrows; row++) {
      ACE_TString cur_name;
      if (in_params.get_cell (cur_name, row, col) == 0) {
         long d = FlyLib_Double::to_long (cur_name.c_str ());
            ret.push_back(d);
      }
    }
  }
    return ret;
}

std::vector<std::string> f4(FLYLIB_OPAQUE _in_params) {
  FlyLib_Multi in_params (_in_params);
  int nrows (in_params.num_rows ());
  int ncols (in_params.num_cols ());

    std::vector<std::string> ret;
if (ncols>1) return ret;
  for (int col = 0; col < ncols; col ++) {
    for (int row = 0; row < nrows; row++) {
      ACE_TString cur_name;
      if (in_params.get_cell (cur_name, row, col) == 0) {
            ret.push_back(std::string(cur_name.c_str()));
      }
    }
  }
    return ret;
}

std::vector<reposit::property_t> f3(FLYLIB_OPAQUE _in_params) {
  FlyLib_Multi in_params (_in_params);
  int nrows (in_params.num_rows ());
  int ncols (in_params.num_cols ());

    std::vector<reposit::property_t> ret;
if (ncols>1) return ret;
  for (int col = 0; col < ncols; col ++) {
    for (int row = 0; row < nrows; row++) {
      ACE_TString cur_name;
      if (in_params.get_cell (cur_name, row, col) == 0) {
         long d = FlyLib_Double::to_long (cur_name.c_str ());
            ret.push_back(d);
      }
    }
  }
    return ret;
}

std::vector<QuantLib::Date> f5(FLYLIB_OPAQUE _in_params) {
  FlyLib_Multi in_params (_in_params);
  int nrows (in_params.num_rows ());
  int ncols (in_params.num_cols ());

    std::vector<QuantLib::Date> ret;
if (ncols>1) return ret;
  for (int col = 0; col < ncols; col ++) {
    for (int row = 0; row < nrows; row++) {
      ACE_TString cur_name;
      if (in_params.get_cell (cur_name, row, col) == 0) {
         long d = FlyLib_Double::to_long (cur_name.c_str ());
            ret.push_back(QuantLib::Date(d));
      }
    }
  }
    return ret;
}

std::vector<bool> f6(FLYLIB_OPAQUE _in_params) {
  FlyLib_Multi in_params (_in_params);
  int nrows (in_params.num_rows ());
  int ncols (in_params.num_cols ());

    std::vector<bool> ret;
if (ncols>1) return ret;
  for (int col = 0; col < ncols; col ++) {
    for (int row = 0; row < nrows; row++) {
      ACE_TString cur_name;
      if (in_params.get_cell (cur_name, row, col) == 0) {
         //long d = FlyLib_Double::to_long (cur_name.c_str ());
            std::string s(cur_name.c_str());
            std::transform(s.begin(), s.end(), s.begin(), ::toupper);
            if ("TRUE" == s || "YES" == s)
                ret.push_back(true);
            else
                ret.push_back(false);
      }
    }
  }
    return ret;
}

//void debug_flylib(FLYLIB_OPAQUE _in_params) {
//  FlyLib_Multi in_params (_in_params);
//  int nrows (in_params.num_rows ());
//  int ncols (in_params.num_cols ());
//CFY_LOG_MESSAGE("debug_flylib", "nrows=" << nrows);
//CFY_LOG_MESSAGE("debug_flylib", "ncols=" << ncols);
//  for (int col = 0; col < ncols; col ++) {
//    for (int row = 0; row < nrows; row++) {
//      ACE_TString cur_name;
//      if (in_params.get_cell (cur_name, row, col) == 0) {
//CFY_LOG_MESSAGE("debug_flylib", "col=" << col << " row=" << row << " cur_name=" << cur_name.c_str());
//      }
//    }
//  }
//}

std::vector<QuantLib::Period> f7(FLYLIB_OPAQUE _in_params) {
  FlyLib_Multi in_params (_in_params);
  int nrows (in_params.num_rows ());
  int ncols (in_params.num_cols ());

    std::vector<QuantLib::Period> ret;
if (ncols>1) return ret;
  for (int col = 0; col < ncols; col ++) {
    for (int row = 0; row < nrows; row++) {
      ACE_TString cur_name;
      if (in_params.get_cell (cur_name, row, col) == 0) {
        QuantLib::Period p_cnv;
        QuantLibAddin::cppToLibrary(cur_name.c_str(), p_cnv);
         ret.push_back(QuantLib::Period(p_cnv));
      }
    }
  }
    return ret;
}

FlyLib_Multi *f8(const std::vector<QuantLib::Date> &v) {
    FlyLib_Multi *ret = FlyLib_Multi::create(1, v.size());
    for (int i=0; i<v.size(); i++)
        ret->set_cell(v[i].serialNumber(), i, 0);
    return ret;
}

FlyLib_Multi *f9(const std::vector<std::string> &v) {
    FlyLib_Multi *ret = FlyLib_Multi::create(1, v.size());
    for (int i=0; i<v.size(); i++)
        ret->set_cell(v[i].c_str(), i, 0);
    return ret;
}

