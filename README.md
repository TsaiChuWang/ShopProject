# ShopProject

## Functions

### Enroll Member 註冊會員

**Input**
|Parameter| Type | Illustration |
| :--: | :--: | :-- |
| name_member | string | 會員名稱 |
| email_member | string | 會員的emaul,視作帳號使用 |
| password_member | string | 會員的密碼 |

**Database**
Insert a new data about member with atttributes
_id,name_member,date_enrolled,email_member,password_member,balance_member

*balance_member*: 會員的餘額,註冊的時候是0元

**Output**
|Parameter| Type | Illustration |
| :--: | :--: | :-- |
| _id | string | 會員的uuid |




## About server

## About client

|Folder| Illustration|
| :--: | :-- |
| HTTPRequestGetTest | Project to test http request about get ,z.B:http://140.113.213.57:5125/view_commodity |
| HTTPRequestPostTest | Project to test http request about post ,z.B:http://140.113.213.57:5125/enroll_member |

## About reference

[HTTPRequest](https://github.com/elnormous/HTTPRequest)

