module.exports = {
    errorResponse: function(message, res) { //error
        return res.status(500).json({ result: {}, message: message, success: 0, statusCode: 500 });
    },
    successResponse: function(message, res, data) { //success
        return res.status(200).json({ result: data, message: message, success: 1, statusCode: 200 });
    },
    infoResponse: function(message, res) { // if there is nothing to send
        return res.status(240).json({ result: {}, message: message, success: 0, statusCode: 200 });
    },
    notFoundResponse: function(message, res) {
        return res.status(404).json({ result: {}, message: message, success: 0, statusCode: 404 });
    },
    unauthorizedRequest: function(message, res) {
        return res.status(401).json({ result: {}, message: message, success: 0, statusCode: 401 });
    }
}
