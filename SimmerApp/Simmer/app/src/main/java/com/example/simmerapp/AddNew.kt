package com.example.simmerapp

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.Menu
import android.view.MenuItem
import android.widget.Button
import android.widget.ImageButton
import android.widget.TextView
import android.widget.Toast
import java.io.IOException
import okhttp3.*

class AddNew : AppCompatActivity() {

    private val client = OkHttpClient()

    private lateinit var rName: TextView
    private lateinit var rTime: TextView
    private lateinit var rServings: TextView
    private lateinit var rDesc:TextView
    private lateinit var ingredient1: TextView
    private lateinit var ingredient2: TextView
    private lateinit var ingredient3: TextView
    private lateinit var ingredient4: TextView
    private lateinit var tvAmt: TextView
    private lateinit var tvAmt2: TextView
    private lateinit var tvAmt3: TextView
    private lateinit var tvAmt4: TextView
    private lateinit var btnSubmit: Button
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_add_new)

        val buttonBackToMainFromBeef = findViewById<ImageButton>(R.id.btnBackarrowAdd)

        // Set the OnClickListener to go back to MainActivity when clicked
        buttonBackToMainFromBeef.setOnClickListener {
            // Create an intent to go back to MainActivity
            val intent = Intent(this, MainActivity::class.java)
            startActivity(intent)
        }

        rName = findViewById(R.id.TvName)
        rTime = findViewById(R.id.TvTime)
        rServings = findViewById(R.id.TvServes)
        rDesc = findViewById(R.id.TvDesc)
        btnSubmit = findViewById(R.id.Submit)
        ingredient1 = findViewById(R.id.tvIng)
        ingredient2 = findViewById(R.id.tvIng2)
        ingredient3 = findViewById(R.id.tvIng3)
        ingredient4 = findViewById(R.id.tvIng4)
        tvAmt = findViewById(R.id.tvAmt)
        tvAmt2 = findViewById(R.id.tvAmt2)
        tvAmt3 = findViewById(R.id.tvAmt3)
        tvAmt4 = findViewById(R.id.tvAmt4)


        btnSubmit.setOnClickListener(){
            val rName = rName.text.toString()
            val rTime = rTime.text.toString()
            val rServes = rServings.text.toString()
            val description = rDesc.text.toString()
            val ing1 = ingredient1.text.toString()
            val ing2 = ingredient2.text.toString()
            val ing3 = ingredient3.text.toString()
            val ing4 = ingredient4.text.toString()
            val amt1 = tvAmt.text.toString()
            val amt2 = tvAmt2.text.toString()
            val amt3 = tvAmt3.text.toString()
            val amt4 = tvAmt4.text.toString()

            sendPostRequest(rName, rTime, description, rServes)
        }

    }
    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.menu, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {

        when(item.itemId){
            R.id.home -> {val intent = Intent(this, MainActivity::class.java)
                startActivity(intent)}
            R.id.about_contacts -> {val intent = Intent(this, AboutUs::class.java)
                startActivity(intent)}
            R.id.favorites -> Toast.makeText(this, "Currently Not Available", Toast.LENGTH_SHORT).show()
        }
        return super.onOptionsItemSelected(item)
    }


    private fun sendPostRequest(recipeName: String, recipeTime: String, description: String, servings: String) {
        Log.d("PostRequest", "Preparing POST request with: name=$recipeName, time=$recipeTime, servings=$servings, desc=$description")

        val formBody = FormBody.Builder()
            .add("recipeName", recipeName)
            .add("recipeTime", recipeTime)
            .add("description", description)
            .add("servings", servings)
            .build()

        val request = Request.Builder()
            .url("http://10.0.2.2/Android_PHP_Database/insert.php")
            .post(formBody)
            .build()

        Log.d("PostRequest", "Request built, sending...")

        client.newCall(request).enqueue(object : Callback {
            override fun onFailure(call: Call, e: IOException) {
                Log.e("PostRequest", "Network Error: ${e.message}", e)
                runOnUiThread {
                    Toast.makeText(this@AddNew, "Network Error: ${e.message}", Toast.LENGTH_LONG).show()
                }
            }

            override fun onResponse(call: Call, response: Response) {
                val body = response.body?.string()
                Log.d("PostRequest", "Response code: ${response.code}, body: $body")
                runOnUiThread {
                    if (response.isSuccessful) {
                        Toast.makeText(this@AddNew, "Recipe Added Successfully", Toast.LENGTH_SHORT).show()
                    } else {
                        Toast.makeText(this@AddNew, "Failed to Add Recipe", Toast.LENGTH_SHORT).show()
                    }
                }
            }
        })
    }


}

