#include <string>

using std::string;

enum ACLGroupTypeEnum {
    ACL_GROUP_ALL_USERS,
    ACL_GROUP_AUTHENTICATED_USERS
};

const string RGW_USER_ANON_ID = "";
const string rgw_uri_all_users = "";
const string rgw_uri_auth_users = "";

class RGWAccessControlPolicy_S3 {
public:
    bool compare_group_name(string& id, ACLGroupTypeEnum group);
};