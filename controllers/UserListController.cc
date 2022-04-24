#include <cctype>
#include <drogon/HttpAppFramework.h>
#include <iostream>
#include <string>
#include <vector>

#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <drogon/HttpViewData.h>

#include "../models/models.hpp"
#include "UserListController.h"

using namespace drogon;
using namespace drogon_model;
using namespace drogon_model::sqlite3;

template <class T> std::vector<T> getModelObjectVec() {
  return orm::Mapper<T>(app().getDbClient()).findAll();
}

std::string titilize(std::string str) {
  // converting first character to uppercase
  str[0] = std::toupper(str[0]);
  return str;
}

void UserListController::asyncHandleHttpRequest(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback) {

  /** Make vector of objects, then vector of their text values */
  std::vector<User> userVec = getModelObjectVec<User>();
  std::vector<std::string> userNameVec;

  auto questionVec = getModelObjectVec<Question>();
  std::vector<std::string> questionTxtVec;

  auto categoryVec =
      orm::Mapper<Category>(app().getDbClient()).findAll();
  std::vector<std::string> categoryNameVec;

  auto ormSolvedVec = orm::Mapper<Solved>(app().getDbClient()).findAll();

  /** Initialize vector of text values */
  for (auto userObj : userVec)
    userNameVec.push_back(titilize(userObj.getValueOfName()));

  for (auto quesObj : questionVec)
    questionTxtVec.push_back(quesObj.getValueOfText());

  for (auto categObj : categoryVec)
    categoryNameVec.push_back(categObj.getValueOfName());
    
  /** Insert text values into `data` */
  HttpViewData data;
  data.insert("userNameVec", userNameVec);
  data.insert("questionTxtVec", questionTxtVec);
  data.insert("categoryNameVec", categoryNameVec);
  data.insert("ormSolvedVec", ormSolvedVec);

  auto resp = HttpResponse::newHttpViewResponse("InformationList.csp", data);
  callback(resp);
}
