/**
 *
 *  Question.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Question.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::sqlite3;

const std::string Question::Cols::_id = "id";
const std::string Question::Cols::_text = "text";
const std::string Question::Cols::_answer_id = "answer_id";
const std::string Question::Cols::_category_id = "category_id";
const std::string Question::primaryKeyName = "id";
const bool Question::hasPrimaryKey = true;
const std::string Question::tableName = "question";

const std::vector<typename Question::MetaData> Question::metaData_={
{"id","uint64_t","integer",8,1,1,1},
{"text","std::string","text",0,0,0,1},
{"answer_id","uint64_t","integer",8,0,0,1},
{"category_id","uint64_t","integer",8,0,0,1}
};
const std::string &Question::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Question::Question(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<uint64_t>(r["id"].as<uint64_t>());
        }
        if(!r["text"].isNull())
        {
            text_=std::make_shared<std::string>(r["text"].as<std::string>());
        }
        if(!r["answer_id"].isNull())
        {
            answerId_=std::make_shared<uint64_t>(r["answer_id"].as<uint64_t>());
        }
        if(!r["category_id"].isNull())
        {
            categoryId_=std::make_shared<uint64_t>(r["category_id"].as<uint64_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 4 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<uint64_t>(r[index].as<uint64_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            text_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            answerId_=std::make_shared<uint64_t>(r[index].as<uint64_t>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            categoryId_=std::make_shared<uint64_t>(r[index].as<uint64_t>());
        }
    }

}

Question::Question(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            text_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            answerId_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[2]].asUInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            categoryId_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[3]].asUInt64());
        }
    }
}

Question::Question(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson["id"].asUInt64());
        }
    }
    if(pJson.isMember("text"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["text"].isNull())
        {
            text_=std::make_shared<std::string>(pJson["text"].asString());
        }
    }
    if(pJson.isMember("answer_id"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["answer_id"].isNull())
        {
            answerId_=std::make_shared<uint64_t>((uint64_t)pJson["answer_id"].asUInt64());
        }
    }
    if(pJson.isMember("category_id"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["category_id"].isNull())
        {
            categoryId_=std::make_shared<uint64_t>((uint64_t)pJson["category_id"].asUInt64());
        }
    }
}

void Question::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            text_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            answerId_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[2]].asUInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            categoryId_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[3]].asUInt64());
        }
    }
}

void Question::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson["id"].asUInt64());
        }
    }
    if(pJson.isMember("text"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["text"].isNull())
        {
            text_=std::make_shared<std::string>(pJson["text"].asString());
        }
    }
    if(pJson.isMember("answer_id"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["answer_id"].isNull())
        {
            answerId_=std::make_shared<uint64_t>((uint64_t)pJson["answer_id"].asUInt64());
        }
    }
    if(pJson.isMember("category_id"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["category_id"].isNull())
        {
            categoryId_=std::make_shared<uint64_t>((uint64_t)pJson["category_id"].asUInt64());
        }
    }
}

const uint64_t &Question::getValueOfId() const noexcept
{
    const static uint64_t defaultValue = uint64_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<uint64_t> &Question::getId() const noexcept
{
    return id_;
}
void Question::setId(const uint64_t &pId) noexcept
{
    id_ = std::make_shared<uint64_t>(pId);
    dirtyFlag_[0] = true;
}
const typename Question::PrimaryKeyType & Question::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Question::getValueOfText() const noexcept
{
    const static std::string defaultValue = std::string();
    if(text_)
        return *text_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Question::getText() const noexcept
{
    return text_;
}
void Question::setText(const std::string &pText) noexcept
{
    text_ = std::make_shared<std::string>(pText);
    dirtyFlag_[1] = true;
}
void Question::setText(std::string &&pText) noexcept
{
    text_ = std::make_shared<std::string>(std::move(pText));
    dirtyFlag_[1] = true;
}

const uint64_t &Question::getValueOfAnswerId() const noexcept
{
    const static uint64_t defaultValue = uint64_t();
    if(answerId_)
        return *answerId_;
    return defaultValue;
}
const std::shared_ptr<uint64_t> &Question::getAnswerId() const noexcept
{
    return answerId_;
}
void Question::setAnswerId(const uint64_t &pAnswerId) noexcept
{
    answerId_ = std::make_shared<uint64_t>(pAnswerId);
    dirtyFlag_[2] = true;
}

const uint64_t &Question::getValueOfCategoryId() const noexcept
{
    const static uint64_t defaultValue = uint64_t();
    if(categoryId_)
        return *categoryId_;
    return defaultValue;
}
const std::shared_ptr<uint64_t> &Question::getCategoryId() const noexcept
{
    return categoryId_;
}
void Question::setCategoryId(const uint64_t &pCategoryId) noexcept
{
    categoryId_ = std::make_shared<uint64_t>(pCategoryId);
    dirtyFlag_[3] = true;
}

void Question::updateId(const uint64_t id)
{
    id_ = std::make_shared<uint64_t>(id);
}

const std::vector<std::string> &Question::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "text",
        "answer_id",
        "category_id"
    };
    return inCols;
}

void Question::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getText())
        {
            binder << getValueOfText();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getAnswerId())
        {
            binder << getValueOfAnswerId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getCategoryId())
        {
            binder << getValueOfCategoryId();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Question::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    return ret;
}

void Question::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getText())
        {
            binder << getValueOfText();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getAnswerId())
        {
            binder << getValueOfAnswerId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getCategoryId())
        {
            binder << getValueOfCategoryId();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Question::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=(Json::UInt64)getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getText())
    {
        ret["text"]=getValueOfText();
    }
    else
    {
        ret["text"]=Json::Value();
    }
    if(getAnswerId())
    {
        ret["answer_id"]=(Json::UInt64)getValueOfAnswerId();
    }
    else
    {
        ret["answer_id"]=Json::Value();
    }
    if(getCategoryId())
    {
        ret["category_id"]=(Json::UInt64)getValueOfCategoryId();
    }
    else
    {
        ret["category_id"]=Json::Value();
    }
    return ret;
}

Json::Value Question::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 4)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=(Json::UInt64)getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getText())
            {
                ret[pMasqueradingVector[1]]=getValueOfText();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getAnswerId())
            {
                ret[pMasqueradingVector[2]]=(Json::UInt64)getValueOfAnswerId();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getCategoryId())
            {
                ret[pMasqueradingVector[3]]=(Json::UInt64)getValueOfCategoryId();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=(Json::UInt64)getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getText())
    {
        ret["text"]=getValueOfText();
    }
    else
    {
        ret["text"]=Json::Value();
    }
    if(getAnswerId())
    {
        ret["answer_id"]=(Json::UInt64)getValueOfAnswerId();
    }
    else
    {
        ret["answer_id"]=Json::Value();
    }
    if(getCategoryId())
    {
        ret["category_id"]=(Json::UInt64)getValueOfCategoryId();
    }
    else
    {
        ret["category_id"]=Json::Value();
    }
    return ret;
}

bool Question::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("text"))
    {
        if(!validJsonOfField(1, "text", pJson["text"], err, true))
            return false;
    }
    else
    {
        err="The text column cannot be null";
        return false;
    }
    if(pJson.isMember("answer_id"))
    {
        if(!validJsonOfField(2, "answer_id", pJson["answer_id"], err, true))
            return false;
    }
    else
    {
        err="The answer_id column cannot be null";
        return false;
    }
    if(pJson.isMember("category_id"))
    {
        if(!validJsonOfField(3, "category_id", pJson["category_id"], err, true))
            return false;
    }
    else
    {
        err="The category_id column cannot be null";
        return false;
    }
    return true;
}
bool Question::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                  const std::vector<std::string> &pMasqueradingVector,
                                                  std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[2] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[3] + " column cannot be null";
            return false;
        }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Question::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("text"))
    {
        if(!validJsonOfField(1, "text", pJson["text"], err, false))
            return false;
    }
    if(pJson.isMember("answer_id"))
    {
        if(!validJsonOfField(2, "answer_id", pJson["answer_id"], err, false))
            return false;
    }
    if(pJson.isMember("category_id"))
    {
        if(!validJsonOfField(3, "category_id", pJson["category_id"], err, false))
            return false;
    }
    return true;
}
bool Question::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Question::validJsonOfField(size_t index,
                                const std::string &fieldName,
                                const Json::Value &pJson,
                                std::string &err,
                                bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }
            if(!pJson.isUInt64())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 2:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isUInt64())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 3:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isUInt64())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}