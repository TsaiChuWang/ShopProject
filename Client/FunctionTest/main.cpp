//
//  HTTPRequest
//

#include <iostream>
#include <fstream>
#include "HTTPRequest.hpp"

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

//上傳商品售賣
std::string upload_commodity(std::string _id_seller, std::string name_commodity,int price, int inventory) {
    std::string pricestr= std::to_string(price);
    std::string inventorystr = std::to_string(inventory);
    try
    {
        http::Request request{ "http://140.113.213.57:5125/upload_commodity" };
        const std::string body = "{\"_id_seller\": \"" + _id_seller + "\", \"name_commodity\": \"" + name_commodity + "\", \"price\": \"" + pricestr + "\", \"inventory\": \"" + inventorystr+"\"}";
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

//查看商品列表
std::string view_commodity() {
    try
    {
        // you can pass http::InternetProtocol::V6 to Request to make an IPv6 request
        http::Request request{ "http://140.113.213.57:5125/view_commodity" };

        // send a get request
        const auto response = request.send("GET");
        std::cout << std::string{ response.body.begin(), response.body.end() } << '\n'; // print the result
        return std::string{ response.body.begin(), response.body.end() };
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }
    return "ERROR";
}

//B向A購買商品
std::string buy_commodity(std::string _id_buyer, std::string _id_seller, std::string _id_commdity, int number) {
    std::string numberstr = std::to_string(number);
    try
    {
        http::Request request{ "http://140.113.213.57:5125/buy_commodity" };
        const std::string body = "{\"_id_buyer\": \"" + _id_buyer + "\", \"_id_seller\": \"" + _id_seller + "\", \"_id_commdity\": \"" + _id_commdity + "\", \"number\": \"" + numberstr + "\"}";
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

int main(int argc, const char* argv[])
{
    int a = -1;
    std::cin >> a;
    std::string str = "";
    if (a == 0) {
        str = enroll_member("test_member_C","test_member_C@gmail.com","12345678");
        std::cout << str << std::endl;
    }
    else if (a == 1) {
        str = login_member("test_member_A@gmail.com", "12345678");
        std::cout << str << std::endl;
    }
    else if (a == 2) {
        int balance = store_balance("c667e7c9d67511edb74a08002765f803", 200);
        std::cout << balance << std::endl;
    }
    else if (a == 3) { 
        str = upload_commodity("c667e7c9d67511edb74a08002765f803", "cake",20,100);
        std::cout << str << std::endl;
    }
    else if (a == 4) {
        str = view_commodity();
        std::cout << str << std::endl;
    }
    else if (a == 5) {
        str = buy_commodity("fc5c7e5dd6b111ed941508002765f803", "c667e7c9d67511edb74a08002765f803", "491dd85fd68411ed9c4a08002765f803", 2);
        std::cout << str << std::endl;
    }else std::cout << "error\n";

    return EXIT_SUCCESS;
}
