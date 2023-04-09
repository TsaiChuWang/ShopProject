# ShopProject


![ 架構圖](./images/structure.png)

## Functions

### Enroll Member 註冊會員

**Input**
|Parameter| Type | Illustration |
| :--: | :--: | :-- |
| name_member | string | 會員名稱 |
| email_member | string | 會員的email,視作帳號使用 |
| password_member | string | 會員的密碼 |

**Database**

Insert a new data about member with atttributes
_id,name_member,date_enrolled,email_member,password_member,balance_member

*balance_member*: 會員的餘額,註冊的時候是0元

**Output**
|Parameter| Type | Illustration |
| :--: | :--: | :-- |
| _id | string | 會員的uuid |

```cpp
//註冊新的會員
std::string enroll_member(std::string name_member, std::string email_member, std::string password_member) {
    try
    {
        http::Request request{ "http://140.113.213.57:5125/enroll_member" };
        const std::string body = "{\"name_member\": \""+name_member+"\", \"email_member\": \"" +email_member+"\", \"password_member\": \"" +password_member+"\"}";
        const auto response = request.send("POST", body, {
            {"Content-Type", "application/json"}
            });
        std::cout << "_id= " << std::string{response.body.begin(), response.body.end()} << '\n'; // print the result
        return std::string{ response.body.begin(), response.body.end() };
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }

    return "ERROR:ENROLL NEW MEMBER ACCOUNT FAILED!";
}
```
### Login Member Account 登入會員

**Input**
|Parameter| Type | Illustration |
| :--: | :--: | :-- |
| email_member | string | 會員的email,視作帳號使用 |
| password_member | string | 會員的密碼 |

**Database**

Find data about member with atttributes and return 
_id,name_member,date_enrolled,email_member,password_member,balance_member

**Output**
|Parameter| Type | Illustration |
| :--: | :--: | :-- |
| _id | string | 會員的uuid |
| name_member | string | 會員名稱 |
| date_enrolled | date | 會員的註冊日期 |
| email_member | string | 會員的email,視作帳號使用 |
| password_member | string | 會員的密碼 |
| balance_member | int | 會員的餘額 |

```cpp
//登入已有的會員帳號
std::string login_member(std::string email_member, std::string password_member) {
    try
    {
        http::Request request{ "http://140.113.213.57:5125/login_member" };
        const std::string body = "{\"email_member\": \"" + email_member + "\", \"password_member\": \"" + password_member + "\"}";
        const auto response = request.send("POST", body, {
            {"Content-Type", "application/json"}
            });
        std::cout << "_id= " << std::string{ response.body.begin(), response.body.end() } << '\n'; // print the result
        return std::string{ response.body.begin(), response.body.end() };
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }

    return "ERROR:ENROLL NEW MEMBER ACCOUNT FAILED!";
}
```
### Store Balance 會員儲值

**Input**
|Parameter| Type | Illustration |
| :--: | :--: | :-- |
| _id | string | 會員的uuid |
| balance_member | int | 會員儲值的額度，必須大於0且為整數 |

**Database**

Update the balance of specified member with adding balance posted.

**Output**
|Parameter| Type | Illustration |
| :--: | :--: | :-- |
| balance | int | 會員更新後的餘額 |

```cpp
//儲值到現有帳號
int store_balance(std::string _id, int balance_member) {
    
    std::string balance = std::to_string(balance_member);
    try
    {
        http::Request request{ "http://140.113.213.57:5125/store_balance" };
        const std::string body = "{\"_id\": \"" + _id + "\", \"balance_member\": \"" + balance + "\"}";
        const auto response = request.send("POST", body, {
            {"Content-Type", "application/json"}
            });
        std::cout << "balance= " << std::string{ response.body.begin(), response.body.end() } << '\n'; // print the result
        return std::stoi(std::string{ response.body.begin(), response.body.end() });
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }

    return -1;
}
```
## About server

## About client

|Folder| Illustration|
| :--: | :-- |
| HTTPRequestGetTest | Project to test http request about get ,z.B:http://140.113.213.57:5125/view_commodity |
| HTTPRequestPostTest | Project to test http request about post ,z.B:http://140.113.213.57:5125/enroll_member |

## About reference

[HTTPRequest](https://github.com/elnormous/HTTPRequest)

